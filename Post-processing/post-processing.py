import rosbag2_py
import pandas as pd
import numpy as np
from rclpy.serialization import deserialize_message
from rosidl_runtime_py.utilities import get_message
from collections import defaultdict

# -----------------------------
# CONFIG
# -----------------------------
bag_path = "wheel025/"   # path to bag (MCAP)
time_tolerance = 0.01          # seconds (50 ms sync tolerance)
output_file = "wheel025/output.csv"

# -----------------------------
# READ BAG
# -----------------------------
storage_options = rosbag2_py.StorageOptions(
    uri=bag_path,
    storage_id="mcap"
)

converter_options = rosbag2_py.ConverterOptions(
    input_serialization_format="cdr",
    output_serialization_format="cdr"
)

reader = rosbag2_py.SequentialReader()
reader.open(storage_options, converter_options)

topic_types = reader.get_all_topics_and_types()
type_map = {t.name: t.type for t in topic_types}

data = defaultdict(list)

# -----------------------------
# EXTRACT MESSAGES
# -----------------------------
while reader.has_next():
    topic, raw_data, t = reader.read_next()
    
    msg_type = get_message(type_map[topic])
    msg = deserialize_message(raw_data, msg_type)
    
    timestamp = t * 1e-9  # convert ns → seconds
    
    # Convert message to dict (simple flatten)
    msg_dict = {"time": timestamp}
    
    for field in msg.__slots__:
        value = getattr(msg, field)
        msg_dict[field] = value
    
    data[topic].append(msg_dict)

# -----------------------------
# CREATE DATAFRAMES
# -----------------------------
dfs = {}
for topic, records in data.items():
    df = pd.DataFrame(records)
    df = df.sort_values("time")
    dfs[topic] = df

# -----------------------------
# SYNCHRONIZATION
# -----------------------------
# Use first topic as reference
topics = list(dfs.keys())
base_topic = topics[0]
base_df = dfs[base_topic].copy()

merged_df = base_df.copy()

for topic in topics[1:]:
    df = dfs[topic]
    
    merged_df = pd.merge_asof(
        merged_df.sort_values("time"),
        df.sort_values("time"),
        on="time",
        direction="nearest",
        tolerance=time_tolerance,
        suffixes=("", f"_{topic.replace('/', '_')}")
    )

# -----------------------------
# EXPORT TO EXCEL
# -----------------------------
merged_df.to_csv(output_file, index=False)

print(f"Saved synchronized data to {output_file}")

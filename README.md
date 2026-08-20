# Torque Vectoring

ROS 2 torque-vectoring control software for a four-wheel vehicle. The project contains a reusable C++ control library, a ROS 2 node, reference generators, high- and low-level controllers, traction control, and a Python TCP bridge for connecting ROS 2 to Simulink.

## Project Layout

- `torque-vectoring/`: ROS 2 package and C++ implementation
- `torque-vectoring/include/`: public headers and data structures
- `torque-vectoring/src/`: library and ROS 2 node sources
- `torque-vectoring/test/`: GoogleTest sources
- `tcp_to_ros.py`: TCP bridge between Simulink and ROS 2

## Requirements

- ROS 2 with `rclcpp`, `std_msgs`, and `geometry_msgs`
- C++17 compiler
- CMake 3.16 or newer
- Python 3 with `numpy` and `rclpy`
- A TCP client such as Simulink for the bridge, if required

## Build

Source ROS 2 in a new terminal, then build from the repository root:

```bash
source /opt/ros/<ros-distro>/setup.bash
colcon build --symlink-install
source install/setup.bash
```

The package can also be configured directly with CMake when the required ROS 2 environment is available:

```bash
cmake -S torque-vectoring -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Run

Start the torque-vectoring node:

```bash
source install/setup.bash
ros2 run torque_vectoring torque_vectoring_node
```

Start the Simulink bridge in another terminal:

```bash
source /opt/ros/<ros-distro>/setup.bash
python3 tcp_to_ros.py
```

The bridge listens on all interfaces. Configure the Simulink side to connect to:

- `TCP port 20000`: Simulink to ROS 2 input data
- `TCP port 20001`: ROS 2 to Simulink wheel-torque output

## ROS 2 Interface

### Subscribed topics

| Topic | Type | Meaning |
| --- | --- | --- |
| `/vehicle/throttle` | `std_msgs/msg/Float64` | Driver throttle command |
| `/vehicle/steering` | `std_msgs/msg/Float64` | Driver steering command |
| `/vehicle/yaw_rate` | `std_msgs/msg/Float64` | Measured yaw rate |
| `/vehicle/velocity` | `geometry_msgs/msg/Vector3` | Vehicle velocity; `x` and `y` are used |
| `/vehicle/acceleration` | `geometry_msgs/msg/Vector3` | Vehicle acceleration; `x` and `y` are used |
| `/vehicle/slip_rl` | `std_msgs/msg/Float64` | Rear-left slip percentage |
| `/vehicle/slip_rr` | `std_msgs/msg/Float64` | Rear-right slip percentage |

### Published topics

| Topic | Type | Meaning |
| --- | --- | --- |
| `/vehicle/wheel_torques` | `std_msgs/msg/Float64MultiArray` | `[rear_left_torque, rear_right_torque]` |
| `/vehicle/yaw_rate_reference` | `std_msgs/msg/Float64` | Generated yaw-rate reference |
| `/vehicle/sideslip_reference` | `std_msgs/msg/Float64` | Generated sideslip reference |
| `/vehicle/yaw_moment_request` | `std_msgs/msg/Float64` | High-level yaw-moment request |
| `/vehicle/total_torque_request` | `std_msgs/msg/Float64` | Requested total torque |

The node uses a 1 ms timer for its control loop. Slip values received by the C++ node are interpreted as percentages and converted to ratios.

## TCP Bridge Protocol

Input packets on port 20000 are interpreted as native little-endian `float64` values. The first value is a message flag:

| Flag | Remaining values |
| --- | --- |
| `0` | `throttle`, `steering` |
| `1` | `yaw_rate`, `velocity_x` |
| `2` | `velocity_x`, `velocity_y`, `acceleration_x`, `acceleration_y` |
| `3` | `slip_rl`, `slip_rr` |

Output packets on port 20001 contain two native `float64` values in this order:

```text
rear_left_torque, rear_right_torque
```

The bridge currently publishes its input values on the ROS topics listed above and sends only the first two values of `/vehicle/wheel_torques` back to the connected TCP client.

## Tests

GoogleTest source files are included under `torque-vectoring/test/`. The test target is currently commented out in `torque-vectoring/CMakeLists.txt`, so the tests are not registered with CMake or `ctest` yet.

After enabling the test target, run the tests with:

```bash
cd build
gctest --output-on-failure
```

## License

MIT

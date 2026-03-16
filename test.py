import socket
import numpy as np
import rclpy

from rclpy.node import Node
from std_msgs.msg import Float64
from geometry_msgs.msg import Vector3

HOST = '0.0.0.0'
PORT = 20000
BUFFER_SIZE = 4096


class TCPBridge(Node):

    def __init__(self):
        super().__init__('tcp_vehicle_bridge')

        self.throttle_pub = self.create_publisher(Float64, '/vehicle/throttle', 10)
        self.steering_pub = self.create_publisher(Float64, '/vehicle/steering', 10)
        self.yawrate_pub = self.create_publisher(Float64, '/vehicle/yaw_rate', 10)
        self.velocity_pub = self.create_publisher(Vector3, '/vehicle/velocity', 10)
        self.accel_pub = self.create_publisher(Vector3, '/vehicle/acceleration', 10)

        self.start_server()

    def start_server(self):

        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind((HOST, PORT))
        server_socket.listen(1)

        self.get_logger().info(f"Server listening on {PORT}")

        conn, addr = server_socket.accept()
        self.get_logger().info(f"Connected by {addr}")

        while rclpy.ok():

            data = conn.recv(BUFFER_SIZE)

            if not data:
                break

            uint64_values = np.frombuffer(data, dtype=np.uint64)
            values = uint64_values.view(np.float64)

            if len(values) == 0:
                continue

            flag = int(values[0])

            # TYPE 0
            if flag == 0 and len(values) >= 3:

                throttle = values[1]
                steering = values[2]

                msg_t = Float64()
                msg_s = Float64()

                msg_t.data = throttle
                msg_s.data = steering

                self.throttle_pub.publish(msg_t)
                self.steering_pub.publish(msg_s)

            # TYPE 1
            elif flag == 1 and len(values) >= 2:

                yaw = Float64()
                yaw.data = values[1]

                self.yawrate_pub.publish(yaw)

            # TYPE 2
            elif flag == 2 and len(values) >= 5:

                vx, vy, ax, ay = values[1:5]

                vel = Vector3()
                vel.x = vx
                vel.y = vy

                acc = Vector3()
                acc.x = ax
                acc.y = ay

                self.velocity_pub.publish(vel)
                self.accel_pub.publish(acc)


def main(args=None):

    rclpy.init(args=args)

    node = TCPBridge()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
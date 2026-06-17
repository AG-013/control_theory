#include controller.h


subscriber
/teeterbot/imu
imu_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "drone/gt_odom", 10, std::bind(&Bar::odomCallback, this, std::placeholders::_1));

callback funtion for imu


/**
 * @brief Extracts the yaw angle from a quaternion orientation.
 * Uses tf2 to convert quaternion to roll, pitch, yaw format.
 * @param orientation Quaternion representing orientation.
 * @return Yaw in radians.
 */

double Quadcopter::getYawFromQuaternion(const geometry_msgs::msg::Quaternion &orientation)
{
    tf2::Quaternion q(
        orientation.x,
        orientation.y,
        orientation.z,
        orientation.w);
    double roll, pitch, yaw;
    tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);
    return yaw;
}

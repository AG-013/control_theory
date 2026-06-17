# topics that are being published
/teeterbot/imu
/teeterbot/left_speed
/teeterbot/left_speed_cmd
/teeterbot/left_torque_cmd
/teeterbot/right_speed
/teeterbot/right_speed_cmd
/teeterbot/right_torque_cmd

create subscriber to imu and a call back funtion.
- imu is in quaterninion.
 sample imu message
     sec: 171
    nanosec: 960000000
  frame_id: teeterbot/body_com/imu_sensor
orientation:
  x: 3.2807090377673376e-14
  y: 0.7292726105444334
  z: 3.11972669919669e-14
  w: -0.6842232526812482
orientation_covariance:
- 0.0

angular_velocity:
  x: 4.9917769164064055e-18
  y: 6.138480958992955e-06
  z: 4.277304625397403e-18
angular_velocity_covariance:
- 0.0
linear_acceleration:
  x: 9.780088050391036
  y: 6.632383173481998e-15
  z: -0.6240230178307847
linear_acceleration_covariance:
- 0.0

#ifndef CONTROLLER_H
#define CONTROLLER_H

// ROS 2 Core
#include "rclcpp/rclcpp.hpp"

// Sensor msgs
#include "sensor_msgs/msg/imu.hpp"

//! commands for platform:
namespace commands
{
  enum class teeterbot
  {
    STABLE
    UNSTABLE
    TOPPLED
  };
}

class Controller: public rclcpp::Node

{
public:
/*! @brief Controller constructor 
  * 
  * intialise the callbacks and internal variables
  */
 Controller();

 /*! @brief Controller destructor
  *
  * will tear down the object
  */
 ~Controller () ;

   geometry_msgs::msg::Pose getOdometry(void);
     void odomCallback(const nav_msgs::msg::Odometry &msg);

  sensor_msgs::msg::Imu getImu(void);
  void imuCallback(const sensor_msgs::msg::imu -- figure out what comes --);




}
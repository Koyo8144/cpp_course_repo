#ifndef ROSBOT_CLASS_H
#define ROSBOT_CLASS_H
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"
#include <list>
#include <ros/ros.h>
#include <string>

using namespace std;

class RosbotClass {
/*The first variables we are going to declare are ROS related, 
and they communicate directly with the robot. That's why we set them
private, to keep better control of them.
*/
private:
  // Communicate with nodes
  ros::NodeHandle n;
  // Laser data
  ros::Subscriber laser_sub;
  std::vector<float> laser_range;
  std::string laser_topic;
  // Velocity data
  ros::Publisher vel_pub;
  geometry_msgs::Twist vel_msg;
  std::string vel_topic;
  // Odometry data
  ros::Subscriber odom_sub;
  std::string odom_topic;
  float x_pos;
  float y_pos;
  float z_pos;

  //the two methods that receive directly messages from the robot are set to private:
  void laser_callback(const sensor_msgs::LaserScan::ConstPtr &laser_msg);
  void odom_callback(const nav_msgs::Odometry::ConstPtr &odom_msg);

public:
  /*
  the constructor of the class. In this case we don't need to pass 
  initial parameters to the RosbotClass, so this constructor remains emtpy. 
  It just initializes the class when an object is instanciated.
  */
  RosbotClass();

  //the initialized functions
  void move();
  void move_forward(int n_secs);
  void move_backwards(int n_secs);
  void turn(string clock, int n_secs);
  void stop_moving();
  float get_position(int param);
  std::list<float> get_position_full();
  double get_time();
  float get_laser(int index);
  float *get_laser_full();
};

/*
Once everything is declared in the header file, the functions and variables can be used 
in the source file called rosbot_class.cpp. The first step is to take the constructor 
and make it initialize all the previous variables to what we need.
*/

#endif

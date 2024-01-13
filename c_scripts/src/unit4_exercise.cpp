#include <iostream>
#include <string>
using namespace std;

class Hobbit {
    public:
    
       Hobbit(string a,float b,int c) {
           name = a;
           height = b;
           age = c;
       } //constructor
    
       string name;
       float height; //in meters
       int age;
    
       void get_name() {
           cout << "This hobbit's name is " << name << endl;
       }
       void convert_height_to_cm();
};

void Hobbit::convert_height_to_cm() {
    height = height*100;
    cout << "Height of the hobbit is " << height << " centimeters" << endl;
}

int main() {
    
    Hobbit first_hobbit("Frodo",1.15,28);
    first_hobbit.get_name();
    
    Hobbit second_hobbit("Sam",1.26,31);
    second_hobbit.get_name();
}





#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>

#include <string>

using namespace std;

// New implemented class
class RosbotMove {
    
public:
    
  RosbotMove(string a) { left_or_right = a; };
  string left_or_right;
    
  // Inherit RosbotClass from the file rosbot_class.h
  RosbotClass rosbot;
  void avoid_wall();
};

void RosbotMove::avoid_wall() {
  // Start moving
  rosbot.move_forward(1);
    
  // Evaluate distance with laser
  while (rosbot.get_laser(0) > 1.75) {
    ROS_INFO_STREAM("Laser frontal reading: " << rosbot.get_laser(0));
    rosbot.move_forward(1);
  }
    
  // Decide if left or right to avoid the wall
  if (left_or_right == "left") {
      
    rosbot.turn("counterclockwise", 3);
    rosbot.move_forward(5);
      
  } else if (left_or_right == "right") {
      
    rosbot.turn("clockwise", 3);
    rosbot.move_forward(5);

  } else {
    ROS_INFO_STREAM("Error: specify a direction for the movement: left or "
                    "right");
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "Rosbot_move_node");
  RosbotMove rosbot_moves("left");
  rosbot_moves.avoid_wall();
}

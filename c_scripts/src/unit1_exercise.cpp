/*
This C++ line includes a header file named rosbot_class.h 
from the rosbot_control directory.
By including the rosbot_class.h header file, 
the C++ program can access the classes, functions, and variables 
defined in that header file.
*/
#include "rosbot_control/rosbot_class.h"
/*
This line of C++ code includes the ROS header file ros.h 
from the ros package, we import this library 
to make use of the classes and functions that ROS provides.
*/
#include <ros/ros.h>

/*
In C++ there are multiple ways to implement a print, but in this chapter we have seen two of them:
printf
cout
The first one is a function that needs the type of the variable to be printed. For example, if we want to print an integer, we specify it with the symbol %i, if it's a float with %f, and if it's a string with %s. In the particular case of printing a string, it needs to be converted to a character by the function c_str().
Finally, it also needs to be accompanied by the include of the class iostream.
The second one is an object that refers to Character OUTput (COUT), which needs to be accompanied by the include of the class iostream, the importing of namespace std (we'll see what this means later), and the symbol <<.
It can also be accompanied by the command endl to jump a line at that point:
*/
#include <iostream>

/*
Note that when including header files, we use " " (quotes) or < > (angle bracket) syntax. 
Using <> tells the preprocessor to search the usual location for system headers 
in order to find the required header, whereas using "" tells the preprocessor 
to first search the directory where the current file is located 
before searching the usual path for system headers.
*/
/*
This line means that we can use the code in the std namespace 
without typing std:: before it. For example, 
we can write cout instead of std::cout. We will explai it more 
in detail later in 1.5.3 Namespace.
*/
/*
C++ has a particular feature called namespaces. 
They allow us to group named entities into a single scope. 
That way, they will only have a meaning inside that namespace. 
Also, we can repeat names of variables, but always inside different 
namespaces.
*/
/*
This line allows us to use all the names inside the namespace std, which so far have been:

string
cout
cin
endl
From now on, if we need to use these, we'll add the line of "using namespace std".
*/
using namespace std;

//create the main function, which is a required function in any C++ program
int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;
  rosbot.move();
  /*
  In this particular case, passing number 1 to the method means 
  we are asking for the coordinate x, number 2 for coordinate y and 
  number 3 for coordinate z.
  C++ is very demanding, it needs us to specify every type of 
  variable we are using, even before using it. 
  */
  float coordinate = rosbot.get_position(1);

  ROS_INFO_STREAM(coordinate);
  
  /*
  return 0; is used to indicate 
  the successful completion of the program.
  Remember that the main function of a program is defined 
  as int main(), which means that it is expected to 
  return an integer value. The integer value returned by the 
  main function is called the exit status or return code of 
  the program. return 0; is for success and return 1; or 
  other numbers for failures.
  */
  return 0;

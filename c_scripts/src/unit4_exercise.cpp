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

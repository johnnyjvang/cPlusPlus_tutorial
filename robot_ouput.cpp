#include <iostream> // iostream header for input/output operations
 
using namespace std;
 
int main() {
    string robot_status = "Active";
    int x_position = 10;
    int y_position = 20;
 
    cout << "Robot Status: " << robot_status << endl;
    cout << "Robot Position: (" << x_position << ", " << y_position << ")" << endl;
 
    cout << "Initializing robot..." << endl;
   
     // Simulating robot initialization
    cout << "Robot initialized successfully!" << endl;
 
    return 0;
}
# include <iostream>
using std::cout;

int main(){
    int i = 1;
    // Declare a reference to i.
    int& j = i;
    cout << "The value of j is: " << j << "\n";
    // Change the value of i.
    i = 5;
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is now: " << j << "\n";
    // Change the value of the reference.
    // Since reference is just another name for the variable,
    // the value of `i` will change when the value of `j` is changed
    j = 7;
    cout << "The value of j is now: " << j << "\n";
    cout << "The value of i is changed to: " << i << "\n";

    int x = 5;
    int z = 6;
    // Print the memory addresses of x and z
    cout << "The address of x is: " << &x << "\n";
    cout << "The address of z is: " << &z << "\n";
}
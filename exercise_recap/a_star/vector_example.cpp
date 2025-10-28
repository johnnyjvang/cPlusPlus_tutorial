// Vector Example - How to use 

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;




int main(){
    // vector<type> vectorName
    // type = string, vectorName = Cars
    // Create a vector called cars that will store strings
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    // Print vector elements
    for (string car : cars) {
        cout << car << "\n";
    }
    cout << cars.size() << endl;

    // for (initialization; condition; increment)
    for (int x=0; x<cars.size(); x++){
        cout << "Number: " << x << " -" << cars[x] << "\n";
    }


}
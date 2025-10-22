// Ask for a number and print whether it’s positive, negative, or zero.

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

string check_number(int x){
    string number_range;
    if (x < 0){
        number_range = "Your Number is negative";
    } else if (x > 0) {
        number_range = "Your Number is positive";
    } else {
        number_range = "Your Number is 0";
    }
    return number_range;
}

int main(){
    int x;
    cout << "Type in a valid integer: ";
    cin >> x;
    if (cin.fail()){
        cout << "Invalid input, please try again" << endl;
    } else{
        cout << check_number(x) << endl;
    }

}
// Use a for loop to print numbers 1–10.
// Use a while loop to print the sum of numbers 1–100.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main(){
    for (int x=0; x<11; x++){
        cout << x << endl;
    }
    int c = 0;
    while(c < 101){
        cout << c << endl;
        c++;
    }
}
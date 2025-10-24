// Ask the user for n, dynamically allocate an int array of size n, fill it, print it, and free the memory using delete[].

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(){
    int n;
    cout <<  "Input integer value: ";
    cin >> n;
    cout << endl;
    if (cin.fail()){
        cout << "Try again, please input valid integer" << endl;
        return 1; // exit early
    }
    int* array = new int[n];
    for (int x=0; x < n; x++){
        array[x] = x;
        cout << array[x] << endl;
    }

    delete[] array;

}
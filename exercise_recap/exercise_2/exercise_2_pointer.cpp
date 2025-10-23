// Create an int variable and a pointer to it. Print both values.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    int number = 67;
    int* ptr = &number; // create a pointer that stores the address of 'number'

    cout << "Value of number: " << number << endl;
    cout << "Address of number (&number): " << &number << endl;
    cout << "Value stored in pointer (ptr): " << ptr << endl;
    cout << "Value pointed to by pointer (*ptr): " << *ptr << endl;

}

// Expression   Meaning	                                Example Output
// -------------------------------------------------------------------
// number	    The integer’s value	                    42
// &number	    The address in memory	                0x7ffee5a1b6bc
// ptr	        The pointer itself (holds an address)	0x7ffee5a1b6bc
// *ptr	        The value stored at that address	    42
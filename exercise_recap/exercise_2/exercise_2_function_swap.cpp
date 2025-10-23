// Write a function swap(int* a, int* b) that swaps two integers using pointers.

#include <iostream>
using std::cout;
using std::endl;

// This function swaps the values of two integers using POINTERS.
// A "pointer" is just a variable that holds the *address* of another variable.
void swap_pointer(int* occurance_a, int* occurance_b) {

    // The * in front of a pointer name means "go to the address and get the value there."
    // So *occurance_a means "the actual number stored at the memory address occurance_a points to."

    // Step 1: Save the value at address occurance_a (the first number)
    int temp = *occurance_a;

    // Step 2: Copy the value from the second number (*occurance_b)
    // into the first number’s address (*occurance_a)
    *occurance_a = *occurance_b;

    // Step 3: Copy the saved value (temp) into the second number’s address
    *occurance_b = temp;

    // When this is done, the two values in memory have been swapped.
    // The addresses didn’t change — just the values at those addresses.
}

int main() {
    int x = 2;
    int y = 3;

    // \n means “new line.” (NOT /n — that’s just a slash and an n)
    cout << "Before swap:" << endl;
    cout << "X = " << x << "\n";
    cout << "Y = " << y << "\n";

    // Here we call the swap function, but it needs POINTERS — not plain numbers.
    // &x means "the memory address of x"
    // &y means "the memory address of y"
    // So we are giving the function the *locations* of x and y,
    // so it can go there and actually change their values.
    swap_pointer(&x, &y);

    cout << "After swap:" << endl;
    cout << "X = " << x << "\n";
    cout << "Y = " << y << "\n";

    return 0;
}

#include <iostream>   // For std::cout, std::endl
#include <fstream>    // For std::ifstream (file input)
#include <string>     // For std::string AND std::getline

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::getline;

// example.txt
// Hello world
// This is a file
// C++ is fun

int main() {
    ifstream file("example.txt");  // Open the file

    if (!file) {
        cout << "Could not open file!" << endl;
        return 1;
    }

    string line;

    // std::getline comes from <string> / <istream>
    // It reads one line of text from the file (up to the newline '\n')
    // The newline is removed from the result stored in 'line'
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();  // Optional — closes automatically when main ends

    return 0;
}

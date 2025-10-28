#include <iostream>

using std::cout;
using std::endl;

enum MixedEnum {
    RED,            // 0 (auto start)
    ORANGE = 5,     // manually set
    YELLOW,         // 6 (auto after 5)
    GREEN = 3,      // resets to 3
    BLUE,           // 4 (auto after 3)
    INDIGO = 10,    // jumps to 10
    VIOLET,         // 11 (auto after 10)
    REPEAT = 3,     // duplicate value allowed
    WHITE,          // 4 (auto after 3 again)
    BLACK = 0       // duplicate of RED
};

int main() {
    cout << "RED = " << RED << endl;
    cout << "ORANGE = " << ORANGE << endl;
    cout << "YELLOW = " << YELLOW << endl;
    cout << "GREEN = " << GREEN << endl;
    cout << "BLUE = " << BLUE << endl;
    cout << "INDIGO = " << INDIGO << endl;
    cout << "VIOLET = " << VIOLET << endl;
    cout << "REPEAT = " << REPEAT << endl;
    cout << "WHITE = " << WHITE << endl;
    cout << "BLACK = " << BLACK << endl;

    return 0;
}

#include <iostream>
using std::endl;
using std::cout;

// 1. Classic unscoped enum (C-style)
enum Color {
    RED,
    GREEN,
    BLUE
};

// 2. Classic enum with assigned integer values
enum Level {
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75
};

// 3. Scoped enum (C++11) — safer, strongly typed
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

// 4. Scoped enum with custom underlying type
enum class Permission : unsigned int {
    READ = 1,
    WRITE = 2,
    EXECUTE = 4
};

// 5. Anonymous enum (no name, used for constants)
enum {
    WIDTH = 800,
    HEIGHT = 600
};

int main() {
    // 1. Classic unscoped enum
    Color c = GREEN;
    cout << "Color value: " << c << endl; // prints 1

    // 2. Classic enum with values
    Level lvl = HIGH;
    cout << "Level value: " << lvl << endl; // prints 75

    // 3. Scoped enum (requires scope access)
    Direction dir = Direction::EAST;
    cout << "Direction value: " << static_cast<int>(dir) << endl; // must cast to int

    // 4. Scoped enum with custom underlying type
    Permission p = Permission::WRITE;
    cout << "Permission value: " << static_cast<unsigned int>(p) << endl;

    // 5. Anonymous enum
    cout << "Screen size: " << WIDTH << "x" << HEIGHT << endl;

    return 0;
}

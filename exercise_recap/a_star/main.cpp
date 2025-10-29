#include <iostream>
#include "board.h"
#include "search.h"
#include "utils.h"

void TestHeuristic();
void TestAddToOpen();
void TestCompare();
void TestSearch();
void TestCheckValidCell();
void TestExpandNeighbors();

int main() {
    int init[2]{0, 0};
    int goal[2]{4, 5};

    auto board = ReadBoardFile("1.board");
    auto solution = Search(board, init, goal);

    PrintBoard(solution);

    PrintTestsHeader();
    TestHeuristic();
    TestAddToOpen();
    TestCompare();
    TestSearch();
    TestCheckValidCell();
    TestExpandNeighbors();

    return 0;
}


// g++ main.cpp board.cpp search.cpp utils.cpp test.cpp -o program
// ./program

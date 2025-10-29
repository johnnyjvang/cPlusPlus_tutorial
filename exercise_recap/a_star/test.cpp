#include <cassert>
#include <iostream>
#include "board.h"
#include "search.h"
#include "utils.h"

using std::cout;
using std::vector;

// ---- Test Heuristic ----
void TestHeuristic() {
    cout << "Testing Heuristic... ";
    assert(Heuristic(0,0,1,1) == 2);
    assert(Heuristic(2,3,2,3) == 0);
    cout << "PASSED\n";
}

// ---- Test AddToOpen ----
void TestAddToOpen() {
    cout << "Testing AddToOpen... ";
    vector<vector<int>> open;
    vector<vector<State>> grid = {{State::kEmpty}};
    AddToOpen(0,0,0,1,open,grid);
    assert(open.size() == 1);
    assert(open[0][0] == 0);
    assert(grid[0][0] == State::kClosed);
    cout << "PASSED\n";
}

// ---- Test Compare ----
void TestCompare() {
    cout << "Testing Compare... ";
    vector<int> a{0,0,1,3}; // f = 4
    vector<int> b{0,0,2,1}; // f = 3
    assert(Compare(a,b) == true);
    cout << "PASSED\n";
}

// ---- Test CheckValidCell ----
void TestCheckValidCell() {
    cout << "Testing CheckValidCell... ";
    vector<vector<State>> grid = {
        {State::kEmpty, State::kObstacle}
    };
    assert(CheckValidCell(0,0,grid) == true);
    assert(CheckValidCell(0,1,grid) == false);
    cout << "PASSED\n";
}

// ---- Test ExpandNeighbors ----
void TestExpandNeighbors() {
    cout << "Testing ExpandNeighbors... ";
    vector<vector<State>> grid = {
        {State::kEmpty, State::kEmpty},
        {State::kEmpty, State::kObstacle}
    };
    vector<vector<int>> open{};
    int goal[2]{1,1};
    vector<int> current{0,0,0,1};

    ExpandNeighbors(current, goal, open, grid);
    assert(open.size() == 1);
    assert(open[0][0] == 0);
    assert(open[0][1] == 1);
    cout << "PASSED\n";
}

// ---- Test Search ----
void TestSearch() {
    cout << "Testing Search... ";
    vector<vector<State>> board = {
        {State::kEmpty, State::kEmpty, State::kEmpty},
        {State::kObstacle, State::kObstacle, State::kEmpty},
        {State::kEmpty, State::kEmpty, State::kEmpty},
    };

    int init[2]{0,0};
    int goal[2]{2,2};
    auto solution = Search(board, init, goal);
    assert(solution.size() == 3);
    cout << "PASSED\n";
}


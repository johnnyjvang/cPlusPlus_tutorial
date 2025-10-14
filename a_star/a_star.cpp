#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::abs;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

enum class State { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

// Directional deltas (up, left, down, right)
const int delta[4][2]{
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

// Parse a line of the board file into a row of States
vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;

    while (sline >> n >> c && c == ',') {
        if (n == 0)
            row.push_back(State::kEmpty);
        else
            row.push_back(State::kObstacle);
    }
    return row;
}

// Read the board file into a 2D vector of States
vector<vector<State>> ReadBoardFile(string path) {
    ifstream myfile(path);
    vector<vector<State>> board{};

    if (myfile) {
        string line;
        while (getline(myfile, line)) {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    } else {
        cout << "❌ Error: Unable to open file: " << path << "\n";
    }
    return board;
}

// Compare the F values of two cells
bool Compare(const vector<int> a, const vector<int> b) {
    int f1 = a[2] + a[3];  // f1 = g1 + h1
    int f2 = b[2] + b[3];  // f2 = g2 + h2
    return f1 > f2;
}

// Sort the open list in descending order
void CellSort(vector<vector<int>>* v) {
    sort(v->begin(), v->end(), Compare);
}

// Calculate the Manhattan distance
int Heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

// Check that a cell is valid: on the grid, not an obstacle, and empty
bool CheckValidCell(int x, int y, vector<vector<State>>& grid) {
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());

    if (on_grid_x && on_grid_y)
        return grid[x][y] == State::kEmpty;

    return false;
}

// Add a node to the open list and mark it as closed
void AddToOpen(int x, int y, int g, int h,
               vector<vector<int>>& openlist,
               vector<vector<State>>& grid) {
    openlist.push_back(vector<int>{x, y, g, h});
    grid[x][y] = State::kClosed;
}

// Expand current node’s neighbors and add them to the open list
void ExpandNeighbors(const vector<int>& current, int goal[2],
                     vector<vector<int>>& openlist,
                     vector<vector<State>>& grid) {
    int x = current[0];
    int y = current[1];
    int g = current[2];

    // Check all 4 neighbors
    for (int i = 0; i < 4; i++) {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        if (CheckValidCell(x2, y2, grid)) {
            int g2 = g + 1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);
            AddToOpen(x2, y2, g2, h2, openlist, grid);
        }
    }
}

// Implementation of A* search algorithm
vector<vector<State>> Search(vector<vector<State>> grid,
                             int init[2], int goal[2]) {
    vector<vector<int>> open{};

    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0], goal[1]);
    AddToOpen(x, y, g, h, open, grid);

    while (!open.empty()) {
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;

        // Check if goal reached
        if (x == goal[0] && y == goal[1]) {
            grid[init[0]][init[1]] = State::kStart;
            grid[goal[0]][goal[1]] = State::kFinish;
            return grid;
        }

        ExpandNeighbors(current, goal, open, grid);
    }

    cout << "No path found!\n";
    return {};
}

// Convert a State to a string for printing
string CellString(State cell) {
    switch (cell) {
        case State::kObstacle: return "⛰️   ";
        case State::kPath:     return "🚗   ";
        case State::kStart:    return "🚦   ";
        case State::kFinish:   return "🏁   ";
        default:               return "0   ";
    }
}

// Print the board
void PrintBoard(const vector<vector<State>>& board) {
    for (auto& row : board) {
        for (auto& cell : row)
            cout << CellString(cell);
        cout << "\n";
    }
}

int main() {
    auto board = ReadBoardFile("numeric_board.txt");

    if (board.empty()) {
        cout << "Error: board could not be loaded.\n";
        return 1;
    }

    int rows = board.size();
    int cols = board[0].size();

    // Set start and goal dynamically
    int init[2]{0, 0};                   // top-left corner
    int goal[2]{rows - 1, cols - 1};     // bottom-right corner

    cout << "Grid size: " << rows << "x" << cols << "\n";
    cout << "Start: (0, 0)\n";
    cout << "Goal: (" << rows - 1 << ", " << cols - 1 << ")\n\n";

    auto solution = Search(board, init, goal);
    PrintBoard(solution);

    return 0;
}

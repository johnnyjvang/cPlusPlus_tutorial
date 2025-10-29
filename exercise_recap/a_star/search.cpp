#include "search.h"
#include <algorithm>
#include <iostream>

using std::abs;
using std::vector;
using std::cout;

const int delta[4][2]{
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

int Heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

bool Compare(const vector<int> a, const vector<int> b) {
    return (a[2] + a[3]) > (b[2] + b[3]);
}

void CellSort(vector<vector<int>>* v) {
    std::sort(v->begin(), v->end(), Compare);
}

bool CheckValidCell(int x, int y, vector<vector<State>>& grid) {
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());
    return (on_grid_x && on_grid_y && grid[x][y] == State::kEmpty);
}

void AddToOpen(int x, int y, int g, int h,
               vector<vector<int>>& openlist,
               vector<vector<State>>& grid) {
    openlist.push_back({x, y, g, h});
    grid[x][y] = State::kClosed;
}

void ExpandNeighbors(const vector<int>& current, int goal[2],
                     vector<vector<int>>& openlist,
                     vector<vector<State>>& grid) {
    int x = current[0], y = current[1], g = current[2];

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

vector<vector<State>> Search(vector<vector<State>> grid,
                             int init[2], int goal[2]) {
    vector<vector<int>> open{};
    int x = init[0], y = init[1];
    int g = 0, h = Heuristic(x, y, goal[0], goal[1]);
    AddToOpen(x, y, g, h, open, grid);

    while (!open.empty()) {
        CellSort(&open);
        auto current = open.back();
        open.pop_back();

        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;

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

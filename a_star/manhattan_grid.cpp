#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <fstream>  // for file writing
using namespace std;

// Cell types
enum class Cell { Empty, Obstacle, Path, Start, Goal };

// Helper to display grid visually
string CellSymbol(Cell c) {
    switch (c) {
        case Cell::Obstacle: return "⬛ ";
        case Cell::Path:     return "🔵 ";
        case Cell::Start:    return "S  ";
        case Cell::Goal:     return "G  ";
        default:             return "⬜ ";
    }
}

// Print visual grid to console
void PrintVisualGrid(const vector<vector<Cell>>& grid) {
    for (auto& row : grid) {
        for (auto& cell : row)
            cout << CellSymbol(cell);
        cout << "\n";
    }
}

// Print numeric grid (0 = empty, 1 = obstacle) to console
void PrintNumericGrid(const vector<vector<Cell>>& grid) {
    for (auto& row : grid) {
        for (auto& cell : row) {
            int val = (cell == Cell::Obstacle) ? 1 : 0;
            cout << val << ",";
        }
        cout << "\n";
    }
}

// Save visual grid to file
void SaveVisualGrid(const vector<vector<Cell>>& grid, const string& filename) {
    ofstream out(filename);
    for (auto& row : grid) {
        for (auto& cell : row)
            out << CellSymbol(cell);
        out << "\n";
    }
    out.close();
    cout << "✅ Saved visual grid to: " << filename << "\n";
}

// Save numeric grid to file
void SaveNumericGrid(const vector<vector<Cell>>& grid, const string& filename) {
    ofstream out(filename);
    for (auto& row : grid) {
        for (auto& cell : row) {
            int val = (cell == Cell::Obstacle) ? 1 : 0;
            out << val << ",";
        }
        out << "\n";
    }
    out.close();
    cout << "✅ Saved numeric grid to: " << filename << "\n";
}

// Generate a guaranteed solvable grid (4-direction movement)
vector<vector<Cell>> GenerateSolvableGrid4Dir(int rows, int cols, double obstacle_prob = 0.3) {
    unsigned seed = (unsigned)chrono::system_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    bernoulli_distribution obstacle_dist(obstacle_prob);

    vector<vector<Cell>> grid(rows, vector<Cell>(cols, Cell::Obstacle));

    // Build solvable path using only right/down moves
    int x = 0, y = 0;
    grid[x][y] = Cell::Path;

    while (x != rows - 1 || y != cols - 1) {
        bool canGoDown = (x < rows - 1);
        bool canGoRight = (y < cols - 1);

        if (canGoDown && canGoRight) {
            // Randomly move down or right
            if (rng() % 2 == 0) ++x;
            else ++y;
        } else if (canGoDown) {
            ++x;
        } else if (canGoRight) {
            ++y;
        }

        grid[x][y] = Cell::Path;
    }

    // Fill the rest randomly
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != Cell::Path) {
                grid[i][j] = obstacle_dist(rng) ? Cell::Obstacle : Cell::Empty;
            }
        }
    }

    // Mark start and goal
    grid[0][0] = Cell::Start;
    grid[rows - 1][cols - 1] = Cell::Goal;
    return grid;
}

int main() {
    int rows = 10;
    int cols = 10;
    double obstacle_prob = 0.25;

    auto grid = GenerateSolvableGrid4Dir(rows, cols, obstacle_prob);

    cout << "🔹 Visual Grid (S = Start, G = Goal, 🔵 = path)\n";
    PrintVisualGrid(grid);
    cout << "\n";

    cout << "🔹 Numeric Grid (0 = empty, 1 = obstacle)\n";
    PrintNumericGrid(grid);
    cout << "\n";

    // Save both versions
    SaveVisualGrid(grid, "visual_board.txt");
    SaveNumericGrid(grid, "numeric_board.txt");

    cout << "\n✅ Both grids successfully generated and saved!\n";
    return 0;
}

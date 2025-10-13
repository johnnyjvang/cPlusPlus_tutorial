#include <iostream>
#include <vector>
#include <chrono>
#include <thread> // for std::this_thread::sleep_for

using std::cout;
using std::vector;

// Function to print the board
void PrintBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell == 0 ? "⬜ " : "⬛ "); // ⬜ = empty, ⬛ = filled
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    const int rows = 6;
    const int cols = 8;
    vector<vector<int>> board(rows, vector<int>(cols, 0));

    cout << "Creating the board...\n\n";

    // Fill the board step-by-step
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = 1;   // mark as filled
            PrintBoard(board); // show the board
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // slow down so we can see
            system("clear"); // or "CLS" on Windows
        }
    }

    cout << "✅ Board created!\n";
    PrintBoard(board);
    return 0;
}

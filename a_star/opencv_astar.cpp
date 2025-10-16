#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
using namespace cv;

enum class State { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

struct Node {
    int x, y, g, h;
    bool operator<(const Node& other) const { return (g + h) > (other.g + other.h); }
};

const int delta[4][2] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

// Generate a random solvable board
vector<vector<State>> GenerateBoard(int rows, int cols, float obstacle_prob = 0.25) {
    vector<vector<State>> board(rows, vector<State>(cols, State::kEmpty));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((float)rand() / RAND_MAX < obstacle_prob)
                board[i][j] = State::kObstacle;
        }
    }
    // Ensure start and goal are clear
    board[0][0] = State::kStart;
    board[rows - 1][cols - 1] = State::kFinish;
    return board;
}

int Heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

bool CheckValidCell(int x, int y, vector<vector<State>>& grid) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == State::kEmpty;
}

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2], vector<Mat>& frames) {
    priority_queue<Node> open;
    open.push({init[0], init[1], 0, Heuristic(init[0], init[1], goal[0], goal[1])});
    grid[init[0]][init[1]] = State::kClosed;

    int rows = grid.size();
    int cols = grid[0].size();
    int cellSize = 40;

    int frameCount = 0;

    while (!open.empty()) {
        Node current = open.top();
        open.pop();
        int x = current.x;
        int y = current.y;

        // mark path
        if (grid[x][y] != State::kStart && grid[x][y] != State::kFinish)
            grid[x][y] = State::kPath;

        // Draw current state
        Mat img(rows * cellSize, cols * cellSize, CV_8UC3, Scalar(255, 255, 255));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                Rect rect(j * cellSize, i * cellSize, cellSize - 1, cellSize - 1);
                Scalar color;
                switch (grid[i][j]) {
                    case State::kObstacle: color = Scalar(0, 0, 0); break;        // black
                    case State::kPath: color = Scalar(0, 255, 255); break;         // yellow
                    case State::kClosed: color = Scalar(200, 200, 200); break;     // gray
                    case State::kStart: color = Scalar(0, 255, 0); break;          // green
                    case State::kFinish: color = Scalar(0, 0, 255); break;         // red
                    default: color = Scalar(255, 255, 255); break;                 // white
                }
                rectangle(img, rect, color, FILLED);
            }
        }
        frames.push_back(img.clone());
        imwrite("frames/frame_" + to_string(frameCount++) + ".png", img);

        // Check goal
        if (x == goal[0] && y == goal[1]) {
            cout << "Goal reached!\n";
            return grid;
        }

        // expand neighbors
        for (int i = 0; i < 4; i++) {
            int x2 = x + delta[i][0];
            int y2 = y + delta[i][1];
            if (CheckValidCell(x2, y2, grid)) {
                int g2 = current.g + 1;
                int h2 = Heuristic(x2, y2, goal[0], goal[1]);
                open.push({x2, y2, g2, h2});
                grid[x2][y2] = State::kClosed;
            }
        }
    }
    cout << "No path found.\n";
    return grid;
}

int main() {
    srand(time(0));
    int rows = 10, cols = 15;
    vector<vector<State>> board = GenerateBoard(rows, cols);

    int init[2]{0, 0};
    int goal[2]{rows - 1, cols - 1};

    vector<Mat> frames;
    system("mkdir -p frames");

    auto solution = Search(board, init, goal, frames);
    cout << "Frames saved in ./frames folder.\n";
    cout << "Use FFmpeg to make GIF:\n";
    cout << "ffmpeg -framerate 10 -i frames/frame_%d.png -vf scale=800:-1 output.gif\n";

    return 0;
}

#include "board.h"
#include <fstream>
#include <sstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;

    while (sline >> n >> c && c == ',') {
        row.push_back(n == 0 ? State::kEmpty : State::kObstacle);
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
    ifstream myfile(path);
    vector<vector<State>> board{};

    if (myfile) {
        string line;
        while (getline(myfile, line)) {
            board.push_back(ParseLine(line));
        }
    }
    return board;
}

string CellString(State cell) {
    switch (cell) {
        case State::kObstacle: return "⛰️   ";
        case State::kPath:     return "🚗   ";
        case State::kStart:    return "🚦   ";
        case State::kFinish:   return "🏁   ";
        default:               return "0   ";
    }
}

void PrintBoard(const vector<vector<State>> board) {
    for (const auto& row : board) {
        for (State cell : row) {
            cout << CellString(cell);
        }
        cout << "\n";
    }
}

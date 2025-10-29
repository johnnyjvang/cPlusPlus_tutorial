#pragma once
#include <string>
#include <vector>

enum class State { kEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

std::vector<State> ParseLine(std::string line);
std::vector<std::vector<State>> ReadBoardFile(std::string path);
void PrintBoard(const std::vector<std::vector<State>> board);
std::string CellString(State cell);

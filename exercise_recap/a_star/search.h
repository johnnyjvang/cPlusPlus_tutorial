#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include "board.h"

int Heuristic(int x1, int y1, int x2, int y2);
bool Compare(const std::vector<int> a, const std::vector<int> b);
void AddToOpen(int x, int y, int g, int h,
               std::vector<std::vector<int>>& openlist,
               std::vector<std::vector<State>>& grid);
bool CheckValidCell(int x, int y, std::vector<std::vector<State>>& grid);
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid,
                                       int init[2], int goal[2]);
void ExpandNeighbors(const std::vector<int>& current, int goal[2],
                     std::vector<std::vector<int>>& openlist,
                     std::vector<std::vector<State>>& grid);

#endif

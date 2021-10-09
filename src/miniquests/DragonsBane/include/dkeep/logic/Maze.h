#pragma once

#include <iostream>
#include <vector>

namespace dkeep {

namespace logic {

enum class Direction {
  kNorth, kSouth, kEast, kWest
};

class Maze {
 public:
  std::vector<std::vector<char>> maze{
      {'X','X','X','X','X','X','X','X','X','X'},
      {'X','H',' ',' ',' ',' ',' ',' ',' ','X'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X',' ',' ',' ',' ',' ',' ','X',' ','E'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X','S','X','X',' ',' ',' ',' ',' ','X'},
      {'X','X','X','X','X','X','X','X','X','X'}};

 public:
  std::vector<std::vector<char>>& GetMaze();

  void ClearCell(int x, int y);
  bool IsExit(int x, int y);
  bool IsThere(char ch, int here_x, int here_y, Direction dir);
  bool CanMoveInto(int x, int y);
  void MoveElement(char ch, int sx, int sy, int dx, int dy);
  void PlaceElement(char ch, int x, int y);
};

}  // namespace dkeep::logic

}  // namespace dkeep

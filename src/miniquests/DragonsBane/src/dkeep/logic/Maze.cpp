#include "dkeep/logic/Maze.h"

namespace dkeep {

namespace logic {

std::vector<std::vector<char>>& Maze::GetMaze() {
  return maze;
}



void Maze::ClearCell(int x, int y) {
  maze[x][y] = ' ';
}

bool Maze::IsExit(int x, int y) {
  return (maze[x][y] == 'E');
}

bool Maze::IsThere(char ch, int here_x, int here_y, Direction dir) {
  if ((dir == Direction::kNorth) && (maze[here_x-1][here_y] == ch))
    return true;
  if ((dir == Direction::kSouth) && (maze[here_x+1][here_y] == ch))
    return true;
  if ((dir == Direction::kEast) && (maze[here_x][here_y+1] == ch))
    return true;
  if ((dir == Direction::kWest) && (maze[here_x][here_y-1] == ch))
    return true;

  return false;
}

bool Maze::CanMoveInto(int x, int y) {
  return ((maze[x][y] == ' ') || (maze[x][y] == 'S'));
}

void Maze::MoveElement(char ch, int sx, int sy, int dx, int dy) {
  ClearCell(sx, sy);
  maze[dx][dy] = ch;
}

void Maze::PlaceElement(char ch, int x, int y) {
  maze[x][y] = ch;
}

}  // namespace dkeep::logic

}  // namespace dkeep

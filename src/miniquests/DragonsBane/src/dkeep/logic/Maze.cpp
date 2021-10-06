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

bool Maze::CanMoveInto(int x, int y) {
  return ((maze[x][y] == ' ') || (maze[x][y] == 'S'));
}

void Maze::MoveElement(char ch, int sx, int sy, int dx, int dy) {
  maze[dx][dy] = ch;
  ClearCell(sx, sy);
}

}  // namespace dkeep::logic

}  // namespace dkeep

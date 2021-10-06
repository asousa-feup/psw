#include "dkeep/logic/Hero.h"

#include "dkeep/logic/Maze.h"

namespace dkeep {

namespace logic {

Hero::Hero(Maze *maze, int x0, int y0)
    : Element(maze, x0, y0) , is_armed(false) , has_key(false) { }



bool Hero::IsArmed() {
  return is_armed;
}

bool Hero::HasKey() {
  return has_key;
}

void Hero::SetArmed(bool is_armed) {
  this->is_armed = is_armed;
}

void Hero::SetHasKey(bool has_key) {
  this->has_key = has_key;
}



void Hero::Move(const Direction dir) {
  int delta_x = 0;
  int delta_y = 0;

  // Check direction
  if (dir == Direction::kNorth) delta_x = -1;
  if (dir == Direction::kSouth) delta_x = 1;
  if (dir == Direction::kEast) delta_y = 1;
  if (dir == Direction::kWest) delta_y = -1;

  // Check if it is possible to move the hero in the maze
  if (maze->CanMoveInto(x + delta_x, y + delta_y)) {
    // - update representation in the maze
    maze->MoveElement('H', x, y, x + delta_x, y + delta_y);

    // - update pose (x,y)
    x += delta_x;
    y += delta_y;
  }
}

}  // namespace dkeep::logic

}  // namespace dkeep

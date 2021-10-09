#include "dkeep/logic/Hero.h"

#include "dkeep/logic/Maze.h"

namespace dkeep {

namespace logic {

Hero::Hero(Maze *maze, int x0, int y0)
    : MoveableElement(maze, x0, y0) , is_armed(false) , has_key(false) ,
      ch('H') { }



bool Hero::IsArmed() {
  return is_armed;
}

bool Hero::HasKey() {
  return has_key;
}

void Hero::SetArmed(bool is_armed) {
  this->is_armed = is_armed;
  if (is_armed) this->ch = 'A';
  maze->PlaceElement(ch, x, y);
}

void Hero::SetHasKey(bool has_key) {
  this->has_key = has_key;
}



void Hero::Move(const Direction dir) {
  //Move(is_armed? 'A':'H', dir);
  Move(ch, dir);
}

}  // namespace dkeep::logic

}  // namespace dkeep

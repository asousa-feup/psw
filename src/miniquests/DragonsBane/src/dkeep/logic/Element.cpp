#include "dkeep/logic/Element.h"

#include "dkeep/logic/Maze.h"

namespace dkeep {

namespace logic {

Element::Element(Maze *maze, int x, int y) {
  this->maze = maze;
  this->x = x;
  this->y = y;
}



int Element::GetX() {
  return x;
}

int Element::GetY() {
  return y;
}

void Element::SetX(int x) {
  this->x = x;
}

void Element::SetY(int y) {
  this->y = y;
}



bool Element::AdjacentTo(Element *other) {
  if ((x-1 == other->x) && (y == other->y)) return true;   // north
  if ((x+1 == other->x) && (y == other->y)) return true;   // south
  if ((x == other->x) && (y+1 == other->y)) return true;   // east
  if ((x == other->x) && (y-1 == other->y)) return true;   // west

  return false;
}

bool Element::Overlap(Element *other) {
  return ((x == other->x) && (y == other->y));
}

}  // namespace dkeep::logic

}  // namespace dkeep

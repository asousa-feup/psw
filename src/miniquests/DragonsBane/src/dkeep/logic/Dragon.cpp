#include "dkeep/logic/Dragon.h"

#include "dkeep/logic/Maze.h"

namespace dkeep {

namespace logic {

Dragon::Dragon(Maze *maze, int x, int y)
    : Element(maze, x, y) , alive(true) { }



bool Dragon::IsAlive() {
  return alive;
}

void Dragon::SetAlive(bool alive) {
  this->alive = alive;
}

}  // namespace dkeep::logic

}  // namespace dkeep

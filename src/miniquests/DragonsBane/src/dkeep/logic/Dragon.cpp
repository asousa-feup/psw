#include "dkeep/logic/Dragon.h"

#include <cstdlib>
#include <ctime>
#include <vector>

#include "dkeep/logic/Maze.h"

namespace dkeep {

namespace logic {

Dragon::Dragon(Maze *maze, int x, int y)
    : MoveableElement(maze, x, y) , alive(true) , over_sword(false) {
  srand(time(NULL));
}



bool Dragon::IsAlive() {
  return alive;
}

void Dragon::SetAlive(bool alive) {
  this->alive = alive;
}



void Dragon::Move() {
  std::vector<int> possible_dir{
    static_cast<int>(Direction::kNorth),
    static_cast<int>(Direction::kSouth),
    static_cast<int>(Direction::kEast),
    static_cast<int>(Direction::kWest),
  };
  int here_x = x;
  int here_y = y;

  Direction dir = static_cast<Direction>(possible_dir[rand() % 4]);

  if (over_sword) {
    if (Move('D', dir)) {
      maze->PlaceElement('S', here_x, here_y);
      over_sword = false;
    }
    return;

  } else {
    if (maze->IsThere('S', here_x, here_y, dir)) {
      Move('F', dir);
      over_sword = true;
    }
  }
  Move('D', dir);
}

}  // namespace dkeep::logic

}  // namespace dkeep

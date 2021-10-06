#pragma once

#include <iostream>

#include "dkeep/logic/Element.h"

namespace dkeep {

namespace logic {

class Dragon : public Element {
 public:
  bool alive;

 public:
  explicit Dragon(Maze *maze, int x, int y);

  bool IsAlive();
  void SetAlive(bool alive);
};

}  // namespace dkeep::logic

}  // namespace dkeep

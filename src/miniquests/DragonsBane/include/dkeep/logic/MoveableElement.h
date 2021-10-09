#pragma once

#include <iostream>

#include "dkeep/logic/Element.h"

namespace dkeep {

namespace logic {

class MoveableElement : public Element {
 public:

 public:
  explicit MoveableElement(Maze *maze, int x, int y);

  bool Move(char ch, const Direction dir);
};

}  // namespace dkeep::logic

}  // namespace dkeep

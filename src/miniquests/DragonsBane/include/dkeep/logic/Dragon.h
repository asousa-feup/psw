#pragma once

#include <iostream>

#include "dkeep/logic/MoveableElement.h"

namespace dkeep {

namespace logic {

class Dragon : public MoveableElement {
 public:
  bool alive;
  bool over_sword;

 public:
  explicit Dragon(Maze *maze, int x, int y);

  bool IsAlive();
  void SetAlive(bool alive);

  using MoveableElement::Move;
  void Move();
};

}  // namespace dkeep::logic

}  // namespace dkeep

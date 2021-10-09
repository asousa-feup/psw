#pragma once

#include <iostream>

#include "dkeep/logic/MoveableElement.h"

namespace dkeep {

namespace logic {

class Hero : public MoveableElement {
 public:
  bool is_armed;
  bool has_key;
  char ch;

 public:
  explicit Hero(Maze *maze, int x0, int y0);
  
  bool IsArmed();
  bool HasKey();
  void SetArmed(bool is_armed);
  void SetHasKey(bool has_key);

  using MoveableElement::Move;
  void Move(const Direction dir);
};

}  // namespace dkeep::logic

}  // namespace dkeep

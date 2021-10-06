#pragma once

#include <iostream>

#include "dkeep/logic/Element.h"

namespace dkeep {

namespace logic {

class Hero : public Element {
 public:
  bool is_armed;
  bool has_key;

 public:
  explicit Hero(Maze *maze, int x0, int y0);
  
  bool IsArmed();
  bool HasKey();
  void SetArmed(bool is_armed);
  void SetHasKey(bool has_key);

  void Move(const Direction dir);
};

}  // namespace dkeep::logic

}  // namespace dkeep

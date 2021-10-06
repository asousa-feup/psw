#pragma once

#include <iostream>

namespace dkeep {

namespace logic {

// Forward declarations
enum class Direction;
class Maze;

class Element {
 public:
  Maze *maze;
  int x;
  int y;

 public:
  explicit Element(Maze *maze, int x, int y);

  int GetX();
  int GetY();
  void SetX(int x);
  void SetY(int y);
  
  bool AdjacentTo(Element *other);
  bool Overlap(Element *other);
};

}  // namespace dkeep::logic

}  // namespace dkeep

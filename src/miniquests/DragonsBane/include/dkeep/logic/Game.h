#pragma once

#include <iostream>
#include <vector>

#include "dkeep/logic/Dragon.h"
#include "dkeep/logic/Hero.h"
#include "dkeep/logic/Maze.h"

namespace dkeep {

namespace logic {

class Game {
 public:
  Maze *maze;
  Hero *hero;
  //Dragon *dragon;
  std::vector<Dragon*> *dragons;
  Element *sword;

  bool has_key;
  std::string output_msg;

 public:
  explicit Game(int ndragons);
  ~Game();

  std::vector<std::vector<char>>& GetMaze();
  std::string& GetOutputMessage();

  bool UpdateGame(char &uc);

 private:
  bool UpdateTurn(const Direction dir);
  bool AreAllDragonsDead();
  void CreateDragons(int ndragons);
  bool DragonsKilledHero();
  bool DragonsMove();
  void TryToPickSword();
  bool TryExit(const Direction dir);
};

}  // namespace dkeep::logic

}  // namespace dkeep

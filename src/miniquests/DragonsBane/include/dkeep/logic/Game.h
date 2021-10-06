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
  Dragon *dragon;
  Element *sword;

  bool has_key;
  std::string output_msg;

 public:
  Game();
  ~Game();

  std::vector<std::vector<char>>& GetMaze();
  std::string& GetOutputMessage();

  bool UpdateGame(char &uc);

 private:
  bool UpdateTurn(const Direction dir);
  bool CheckDragonEncounter();
  void TryToPickSword();
  bool TryExit(const Direction dir);
};

}  // namespace dkeep::logic

}  // namespace dkeep

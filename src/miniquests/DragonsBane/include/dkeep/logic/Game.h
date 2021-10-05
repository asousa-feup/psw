#pragma once

#include <iostream>
#include <vector>

namespace dkeep {

namespace logic {

class Game {
 public:
  std::vector<std::vector<char>> maze{
      {'X','X','X','X','X','X','X','X','X','X'},
      {'X','H',' ',' ',' ',' ',' ',' ',' ','X'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X','D','X','X',' ','X',' ','X',' ','X'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X',' ',' ',' ',' ',' ',' ','X',' ','E'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X',' ','X','X',' ','X',' ','X',' ','X'},
      {'X','K','X','X',' ',' ',' ',' ',' ','X'},
      {'X','X','X','X','X','X','X','X','X','X'}};

  bool has_key;
  int hx, hy;
  std::string output_message;

 public:
  Game();

  std::vector<std::vector<char>>& GetMaze();
  std::string& GetOutputMessage();

  bool Update(char &uc);
};

}  // namespace dkeep::logic

}  // namespace dkeep

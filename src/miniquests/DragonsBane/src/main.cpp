#include <iostream>
#include <vector>

#include "dkeep/logic/Game.h"

void PrintMaze(std::vector<std::vector<char>> &maze);

int main(int argc, char** argv) {

  char uc;
  bool is_game_over = false;
  dkeep::logic::Game *game = new dkeep::logic::Game();

  do {

    // print the maze
    PrintMaze(game->GetMaze());

    // read user command
    std::cout << "cmd> ";
    std::cin >> uc;

    // ignore the other characters
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    // update the game
    is_game_over = game->Update(uc);
    if (!is_game_over)
      std::cout << game->GetOutputMessage() << std::endl;

  } while ((!is_game_over) && (uc != 'q'));

  // final state of the game
  PrintMaze(game->GetMaze());
  std::cout << game->GetOutputMessage() << std::endl;

  std::cout << "Exiting!" << std::endl;

  // delete dynamically allocated variables
  delete game;
}

void PrintMaze(std::vector<std::vector<char>> &maze) {
  for (int i = 0; i < maze.size(); i++) {
    // - print the maze coordinate (i,j)
    for (int j = 0; j < maze[i].size(); j++)
      std::cout << maze[i][j];

    // - add linebreak after each line of the maze
    std::cout << std::endl;
  }
}

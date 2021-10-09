#include <iostream>
#include <string>
#include <vector>

#include "dkeep/logic/Game.h"

int AskNumberOfDragons();
void PrintMaze(std::vector<std::vector<char>> &maze);

int main(int argc, char** argv) {

  char uc;
  bool is_game_over = false;

  int ndragons = AskNumberOfDragons();

  dkeep::logic::Game *game = new dkeep::logic::Game(ndragons);

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
    is_game_over = game->UpdateGame(uc);
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

int AskNumberOfDragons() {
/*
 * std::atoi does not throw an exception when the conversion was not possible
 *
 * for exemplification purposes, we are using std::stoi to use exceptions
 */
  do {
    std::cout << "How many dragons in the maze? (1-4) ";
    
    char n;
    std::cin >> n;
    std::string nstr(1,n);

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    try {
      int nd = std::stoi(nstr);
      if ((nd <= 0) || (nd > 4))
        throw std::invalid_argument("Number must be between 1 and 4");
      
      return nd;
    } catch (std::invalid_argument& e) {
      std::cout << "Please enter a valid number" << std::endl;
    }
  } while (true);
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

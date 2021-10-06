#include "dkeep/logic/Game.h"

namespace dkeep {

namespace logic {

Game::Game() : has_key(false) , output_msg("") {
  maze = new Maze();
  hero = new Hero(maze, 1, 1);
  dragon = new Dragon(maze, 3, 1);
  sword  = new Element(maze, 8, 1);
}

Game::~Game() {
  delete sword;
  delete dragon;
  delete hero;
  delete maze;
}



std::vector<std::vector<char>>& Game::GetMaze() {
  return maze->GetMaze();
}

std::string& Game::GetOutputMessage() {
  return output_msg;
}



bool Game::UpdateGame(char &uc) {
  output_msg = "";

  switch (uc) {
  case 'w': return UpdateTurn(Direction::kNorth);
  case 's': return UpdateTurn(Direction::kSouth);
  case 'd': return UpdateTurn(Direction::kEast);
  case 'a': return UpdateTurn(Direction::kWest);
  }

  return false;
}

bool Game::UpdateTurn(const Direction dir) {
  if (!TryExit(dir)) {
    hero->Move(dir);
    TryToPickSword();
    return CheckDragonEncounter();
  } else return true;
}



bool Game::CheckDragonEncounter() {
  if ((dragon->IsAlive()) && (dragon->AdjacentTo(hero))) {
    if (hero->is_armed) {
      dragon->SetAlive(false);
      maze->ClearCell(dragon->GetX(), dragon->GetY());
      hero->SetHasKey(true);
    } else {
      output_msg = "YOU DIED!";
      return true;
    }
  }
  return false;
}

void Game::TryToPickSword() {
  if (hero->IsArmed()) return;
  hero->SetArmed(hero->Overlap(sword));
}

bool Game::TryExit(const Direction dir) {
  int x = hero->GetX();
  int y = hero->GetY();

  bool next_to_exit = false;

  if ((!next_to_exit) && (dir == Direction::kNorth) && (maze->IsExit(x-1,y)))
    next_to_exit = true;
  if ((!next_to_exit) && (dir == Direction::kSouth) && (maze->IsExit(x+1,y)))
    next_to_exit = true;
  if ((!next_to_exit) && (dir == Direction::kEast) && (maze->IsExit(x,y+1)))
    next_to_exit = true;
  if ((!next_to_exit) && (dir == Direction::kWest) && (maze->IsExit(x,y-1)))
    next_to_exit = true;
  
  if (next_to_exit) {
    if (hero->HasKey()) {
      output_msg = "GREAT! YOU REACHED THE EXIT!";
      return true;
    } else {
      output_msg = "You need a key to open this door.";
      return false;
    }
  }

  return false;
}

}  // namespace dkeep::logic

}  // namespace dkeep

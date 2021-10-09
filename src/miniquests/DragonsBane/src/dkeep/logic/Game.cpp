#include "dkeep/logic/Game.h"

namespace dkeep {

namespace logic {

Game::Game(int ndragons) : has_key(false) , output_msg("") {
  maze = new Maze();
  hero = new Hero(maze, 1, 1);
  //dragon = new Dragon(maze, 3, 1);
  sword  = new Element(maze, 8, 1);

  CreateDragons(ndragons);
}

Game::~Game() {
  delete sword;
  for (std::vector<Dragon*>::iterator it = dragons->begin();
      it != dragons->end(); it++)
    delete (*it);
  delete dragons;
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
    if ((!AreAllDragonsDead()) && (!DragonsKilledHero())) {
      return DragonsMove();
    } else if (AreAllDragonsDead()) return false;
    else return true;
  } else return true;
}



bool Game::AreAllDragonsDead() {
  for (Dragon* dragon : *dragons)
    if (dragon->IsAlive())
      return false;
  
  return true;

/* // Also valid...
 * bool at_least_one_is_alive = false;
 * for (Dragon* dragon : *dragons)
 *   at_least_one_is_alive |= dragon->IsAlive();
 * return (!at_least_one_is_alive);
 */
}

void Game::CreateDragons(int ndragons) {
  dragons = new std::vector<Dragon*>(ndragons);

  for (int i = 0; i < ndragons; i++) {
    (*dragons)[i] = new Dragon(maze, 1+i, 8);
    maze->PlaceElement('D', 1+i, 8);
/*
 * You cannot use push_back when you preallocated the memory for the vector.
 * If you do e.g. ndragons = 4, using push_back adds new elements to the vector
 * with initial size of 4!!!
 */
  }
}

bool Game::DragonsKilledHero() {
  for (Dragon* dragon : *dragons) {
    if ((dragon->IsAlive()) && (dragon->AdjacentTo(hero))) {
      if (hero->is_armed) {
        dragon->SetAlive(false);
        maze->ClearCell(dragon->GetX(), dragon->GetY());
        hero->SetHasKey(AreAllDragonsDead());
      } else {
        output_msg = "YOU DIED!";
        return true;
      }
    }
  }
  return false;
}

bool Game::DragonsMove() {
  for (Dragon* dragon : *dragons) {
    if (!dragon->IsAlive()) continue;
    dragon->Move();
  }
  return DragonsKilledHero();
}

void Game::TryToPickSword() {
  if (hero->IsArmed()) return;
  hero->SetArmed(hero->Overlap(sword));
}

bool Game::TryExit(const Direction dir) {
  int x = hero->GetX();
  int y = hero->GetY();

  bool next_to_exit = maze->IsThere('E', x, y, dir);
  
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

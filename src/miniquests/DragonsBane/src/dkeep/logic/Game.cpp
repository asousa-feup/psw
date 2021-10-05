#include "dkeep/logic/Game.h"

namespace dkeep {

namespace logic {

Game::Game() : hx(1) , hy(1) , has_key(false) , output_message("") { }

std::vector<std::vector<char>>& Game::GetMaze() {
  return maze;
}

std::string& Game::GetOutputMessage() {
  return output_message;
}

bool Game::Update(char &uc) {
  // Initialize
  bool is_game_over = false;
  output_message = "";

  // Process command
  switch (uc) {
    case 'w': // UP
      if (maze[hx-1][hy] == ' ') {  // check for free space
        maze[hx-1][hy] = 'H';
        maze[hx][hy] = ' ';
        hx--;

        // check dragon
        if (maze[hx-1][hy] == 'D') {
          output_message = "YOU DIED!";
          is_game_over = true;
        }
      }
      break;

    case 's': // DOWN
      if (maze[hx+1][hy] == ' ') {  // check for free space
        maze[hx+1][hy] = 'H';
        maze[hx][hy] = ' ';
        hx++;

        // check dragon
        if (maze[hx+1][hy] == 'D') {
          output_message = "YOU DIED!";
          is_game_over = true;
        }

        break;
      }

      if (maze[hx+1][hy] == 'K') {  // check for the key
        maze[hx+1][hy] = 'H';
        maze[hx][hy] = ' ';
        hx++;
        has_key = true;
      }
      break;

    case 'd': // RIGHT
      if (maze[hx][hy+1] == ' ') {  // check for free space
        maze[hx][hy+1] = 'H';
        maze[hx][hy] = ' ';
        hy++;
      }

      if (maze[hx][hy+1] == 'E') {  // check entry
        if (has_key) {
          output_message = "GREAT! YOU REACHED THE EXIT!";
          is_game_over = true;

        } else {
          output_message = "You need a key to open this door.";
        }
      }
      break;

    case 'a': // LEFT
      if (maze[hx][hy-1] == ' ') {  // check for free space
        maze[hx][hy-1] = 'H';
        maze[hx][hy] = ' ';
        hy--;
      }
      break;

    default:
      break;
  }

  // Return game over status
  return is_game_over;
}

}  // namespace dkeep::logic

}  // namespace dkeep

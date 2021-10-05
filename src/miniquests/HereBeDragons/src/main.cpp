#include <iostream>
#include <vector>

void PrintMaze(std::vector<std::vector<char>> &maze) {
  for (int i = 0; i < maze.size(); i++) {
    // - print the maze coordinate (i,j)
    for (int j = 0; j < maze[i].size(); j++)
      std::cout << maze[i][j];

    // - add linebreak after each line of the maze
    std::cout << std::endl;
  }
}

int main(int argc, char** argv) {

  // Store the maze
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

  // Game loop
  int hx = 1, hy = 1;
  char uc;
  bool has_key = false, is_game_over = false;
  do {

    // - print the maze
    PrintMaze(maze);

    // - read user command
    std::cout << "cmd> ";
    std::cin >> uc;

    // - ignore the other characters
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    // - process command
    switch (uc) {
      case 'w': // UP
        if (maze[hx-1][hy] == ' ') {  // check for free space
          maze[hx-1][hy] = 'H';
          maze[hx][hy] = ' ';
          hx--;

          // check dragon
          if (maze[hx-1][hy] == 'D') {
            PrintMaze(maze);
            std::cout << "YOU DIED!" << std::endl;
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
            PrintMaze(maze);
            std::cout << "YOU DIED!" << std::endl;
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
            std::cout << "GREAT! YOU REACHED THE EXIT!" << std::endl;
            is_game_over = true;

          } else {
            std::cout << "You need a key to open this door." << std::endl;
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

  } while ((!is_game_over) && (uc != 'q'));

}

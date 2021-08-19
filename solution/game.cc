#include "game.h"

#include <iostream>

bool PlayerWonCheck(std::vector<std::vector<std::string>> grid, int player) {
  // We can use a for loop since finding horizontal and vertical streaks
  // are the exact same exect the loop in this case would alternate each
  // row and column respectively
  for (int index = 0; index < grid.size(); index++) {
    // since the first [] on grid is the "row" we can have index be the input
    // since we are checking the rows if there is a streak or:
    // "a = b, b = c, a = c"
    if (grid[index][0] == grid[index][1] && grid[index][1] == grid[index][2] &&
        grid[index][0] != "_") {
      std::cout << "Player " << player << " has won horizontally!" << std::endl;
      return true;
      // similar to how we did horizontal but this time reversed because we are
      // checking if there are any vertical streaks
    } else if (grid[0][index] == grid[1][index] &&
               grid[1][index] == grid[2][index] && grid[0][index] != "_") {
      std::cout << "Player " << player << " has won vertically!" << std::endl;
      return true;
    }
  }
  // Diagonals are a bit more brute force in the sense that
  // we dont need any loop to check if "a = b, b = c, a = c"
  // what is interesting is that since we start at (0,0) you can see a
  // pattern where x and y increase by 1 each box
  if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] &&
      grid[1][1] != "_") {
    std::cout << "Player " << player << " has won diagonally!" << std::endl;
    return true;
    // Similar to the previous diagonal we are still looking at the
    // center point (1,1). However, this time the corners are flipped which
    // should be accounted for to properly check if there is a diagonal streak
  } else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] &&
             grid[1][1] != "_") {
    std::cout << "Player " << player << " has won diagonally!" << std::endl;
    return true;
  }
  return false;
}

void PlayerInput(std::vector<std::vector<std::string>> &grid,
                 std::map<std::string, std::vector<int>> &moves,
                 std::vector<std::string> &playerOptions, std::string input,
                 int player) {
  bool passed = false;
  int x, y;
  // We are using a do while because we want to run this at least once to
  // check if the input valid and is a key in the map
  do {
    // This conditional is a fancy way in C++ to find if there is a key in a map
    if (moves.find(input) != moves.end()) {
      // we have to make this true in order to break out of the do while loop
      passed = true;
      // These are to extract the information from the map which is are
      // coordinates in a vector where the first value [0] is x and [1] is y
      x = moves[input][0];
      y = moves[input][1];
      // The following is to delete the key from the map and the
      // array so that players cannot call the same action twice
      moves.erase(input);
      for (int optionIndex = 0; optionIndex < playerOptions.size();
           optionIndex++) {
        if (playerOptions[optionIndex] == input) {
          playerOptions.erase(playerOptions.begin() + optionIndex);
        }
      }
    } else {
      std::cout << "Invalid input, try again: ";
      std::cin >> input;
    }
  } while (!passed);
  // This just overrides the "_" on the grid with the corresponding players sign
  if (player == 1) {
    grid[x][y] = "X";
  } else {
    grid[x][y] = "O";
  }
}

void Display(std::vector<std::vector<std::string>> grid,
             std::vector<std::string> possibleMoves, int canDisplay) {
  for (int rows = 0; rows < grid.size(); rows++) {
    for (int columns = 0; columns < grid.size(); columns++) {
      std::cout << grid[rows][columns];
    }
    // this is just to indent so the following row can print,
    // giving the effect of a 3x3 grid on the console log
    std::cout << std::endl;
  }
  // the reason why I have this if statement is because I dont always want to
  // print this for instance: when a there are no more moves to play, why should
  // we print it?
  if (canDisplay == 1) {
    std::cout << "Possible input moves: ";
    for (int moves = 0; moves < possibleMoves.size(); moves++) {
      // I wish to print out all the remaining moves like: "TL, TM, TR"
      // where the last element does not have a comma
      // my reasoning for this if statement is that if it hits the last
      // element of the vector "n-1" then it would print
      // only the possibleMove left
      if (moves == possibleMoves.size() - 1) {
        std::cout << possibleMoves[moves];
      } else {
        std::cout << possibleMoves[moves] << ",";
      }
    }
    std::cout << "\n";
  }
}

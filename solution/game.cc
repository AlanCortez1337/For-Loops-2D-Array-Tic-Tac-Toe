#include "game.h"

#include <iostream>

bool PlayerWonCheck(std::vector<std::vector<std::string>> grid, int player) {
  // A horizontal or vertical streak always follows a patten which we can take
  // advantage of and use a for loop to alternate through each row and column
  // respectively
  for (int index = 0; index < grid.size(); index++) {
    // since the first [] on grid is the "row" we can have index be the input
    // because we are alternating through the rows for a horizontal streak
    if (grid[index][0] == grid[index][1] && grid[index][1] == grid[index][2] &&
        grid[index][0] != "_") {
      std::cout << "Player " << player << " has won horizontally!" << std::endl;
      return true;
      // Similar to how we did horizontal streaks, we are making index be the
      // what we are sifting through in the 2D vector. This time being columns
      // because we need to check if each column has a vertical streak.
    } else if (grid[0][index] == grid[1][index] &&
               grid[1][index] == grid[2][index] && grid[0][index] != "_") {
      std::cout << "Player " << player << " has won vertically!" << std::endl;
      return true;
    }
  }
  // Diagonals are a bit more "brute force" in the sense that we dont need to
  // loop to check if there is a vertical streak. While there may be a way to do
  // so, what we do for the left to right diagonal is that we can start at [0,0]
  // and check middle with the opposite corner to see if they have the same
  // value.
  if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] &&
      grid[1][1] != "_") {
    std::cout << "Player " << player << " has won diagonally!" << std::endl;
    return true;
    // Similar to the previous diagonal we are still looking at the
    // center point (1,1). However, this time the corners are flipped because
    // visually that would look like a right to left diagonal streak
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
      // we have to make this true in order to break out of the do-while loop
      passed = true;
      // These are to store the values from the map, which are coordinates on
      // the grid. In other words, the values of the map is a vector where the
      // value at [0] is x and [1] is y
      x = moves[input][0];
      y = moves[input][1];
      // The following is to delete the key from the map and the
      // array so that players cannot call the same action twice, causing
      // overlap
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
  // This just overrides the "_" on the grid with the corresponding players move
  // coordinates
  if (player == 1) {
    grid[x][y] = "X";
  } else {
    grid[x][y] = "O";
  }
}

void Display(std::vector<std::vector<std::string>> grid,
             std::vector<std::string> possibleMoves, int canDisplay) {
  for (int rows = 0; rows < grid.size(); rows++) {
    // For loop to go through and print what value is at [rows][columns]
    for (int columns = 0; columns < grid.size(); columns++) {
      std::cout << grid[rows][columns];
    }
    // Necessary indentation once a row is complete to simulate a 3x3 grid
    std::cout << std::endl;
  }
  // This if statement is meant as a simple way to not print the following once
  // there are no more possible moves to play
  if (canDisplay == 1) {
    std::cout << "Possible input moves: ";
    for (int moves = 0; moves < possibleMoves.size(); moves++) {
      // The goal behind this if statement is to print "Possible moves: TL, TM,
      // TR" where there is a comma inbetween each move and no comma after the
      // last value
      if (moves == possibleMoves.size() - 1) {
        std::cout << possibleMoves[moves];
      } else {
        std::cout << possibleMoves[moves] << ",";
      }
    }
    std::cout << "\n";
  }
}

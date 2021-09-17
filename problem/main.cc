#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "game.h"
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                              DO NOT MODIFY
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
int main() {
  // Initialization:
  // We are using a map because we want to attribute a move like "TL" or "Top
  // Left" to a coordinate on the 2d grid, in this case: [0,0]
  std::map<std::string, std::vector<int>> playerMoves = {
      {"TL", {0, 0}}, {"TM", {0, 1}}, {"TR", {0, 2}},
      {"ML", {1, 0}}, {"MM", {1, 1}}, {"MR", {1, 2}},
      {"BL", {2, 0}}, {"BM", {2, 1}}, {"BR", {2, 2}}};
  // This vector is mainly used as an easy way to print out the possible moves
  std::vector<std::string> moveOptions = {"TL", "TM", "TR", "ML", "MM",
                                          "MR", "BL", "BM", "BR"};
  // The following is our 2d array which will be used to navigate through.
  // Another way of looking at this is:
  // {"_", "_", "_"}
  // {"_", "_", "_"}
  // {"_", "_", "_"}
  // where the top left is [0,0] and the bottom right is [2,2]
  std::vector<std::vector<std::string>> game_board = {
      {"_", "_", "_"}, {"_", "_", "_"}, {"_", "_", "_"}};
  // Other necessary variables we need to initialize to get the code working
  int player = 1;
  std::string input;
  int x, y;
  // This is just basic welcome dialog for when the code first runs
  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~\n";
  std::cout << "WELCOME TO TIC-TAC-TOE";
  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~\n";
  std::cout << "For inputs: The first letter is the row and the second is the "
               "column.\n";
  std::cout << "EX: \"TL\" is Top Left\nHere is the Grid: \n";
  // This will be our main loop to keep on running until the game is over
  while (true) {
    // First time Display gets calls is to show the blank board and the possible
    // moves. After the first time, calling this function will show an updated
    // version of the game board and the possible moves the player can input
    Display(game_board, moveOptions, 1);
    std::cout << "Player " << player << " input: ";
    std::cin >> input;
    // Then this function will be where we use the new player's input to change
    // how the grid will look in the backend
    PlayerInput(game_board, playerMoves, moveOptions, input, player);
    // Here we have a conditional to break out of the loop if any player has a
    // winning streak so the loop won't run infinitely
    if (PlayerWonCheck(game_board, player)) {
      Display(game_board, moveOptions, 0);
      break;
      // Here is a conditional to exit the loop if there is a tie or if there
      // are no more moves to play
    } else if (moveOptions.size() == 0) {
      Display(game_board, moveOptions, 0);
      std::cout << "NO WINNERS: TIE" << std::endl;
      break;
    }
    // These if statements are just to swap the player number once their turn
    // is over.
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }
  }

  return 0;
}

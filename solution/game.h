#include <map>
#include <string>
#include <vector>
// Here we define the necessary functions that we are going to use for our
// Tic-Tac-Toe game
#ifndef GAME_H
#define GAME_H
// This functions purpose is to check if any player has won vertically,
// horizontally, or diagonally
bool PlayerWonCheck(std::vector<std::vector<std::string>> grid, int player);
// This function get the input of the current player so that the function can
// delete that option for future play and override the "_" at the appropriate
// spot
void PlayerInput(std::vector<std::vector<std::string>> &grid,
                 std::map<std::string, std::vector<int>> &moves,
                 std::vector<std::string> &playerOptions, std::string input,
                 int player);
// This function's core purpose is just to go through the 2d array and display
// each row each time it is called
void Display(std::vector<std::vector<std::string>> grid,
             std::vector<std::string> possibleMoves, int canDisplay);

#endif // GAME_H

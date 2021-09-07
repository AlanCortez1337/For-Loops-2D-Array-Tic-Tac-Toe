#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"

// #include <sstream>
#include <vector>
#include "../../game.h"

using ::testing::HasSubstr;
// Include the header files from the student solution.
// Use ../../ prefix to locate the student solution folder
// For example:
// #include "../../math.h"

/* Sample Unit test

TEST(Factorial, Zero) {
	ASSERT_EQ(factorial(0), 1);
}

*/
// TESTS
// Blank Board
TEST(TTT, BlankBoard){
  const std::vector<std::vector<std::string>> blankBoard = {{"_", "_", "_"}, {"_", "_", "_"}, {"_", "_", "_"}};
  ASSERT_EQ(PlayerWonCheck(blankBoard, 1), false) << "There might be a problem where your program attributes the blank spaces as a streak.";
  ASSERT_EQ(PlayerWonCheck(blankBoard, 2), false) << "There might be a problem where your program attributes the blank spaces as a streak.";
}
// Horizontal Streak
TEST(TTT, HorizontalStreak){
  const std::vector<std::vector<std::string>> horStreak1 = {{"X", "X", "X"}, {"_", "_", "_"}, {"_", "_", "_"}};
  const std::vector<std::vector<std::string>> horStreak2 = {{"_", "_", "_"}, {"O", "O", "O"}, {"_", "_", "_"}};
  const std::vector<std::vector<std::string>> horStreak3 = {{"X", "X", "O"}, {"O", "X", "X"}, {"O", "O", "O"}};
  ASSERT_EQ(PlayerWonCheck(horStreak1, 1), true) << "If it is currently player 1, it should return true when there is a \"horizontal streak\" or when all the values of gameBoard[0][value] = \"X\"";
  ASSERT_EQ(PlayerWonCheck(horStreak2, 2), true) << "If it is currently player 2, it should return true when there is a \"horizontal streak\" or when all the values of gameBoard[1][value] = \"O\"";
  ASSERT_EQ(PlayerWonCheck(horStreak3, 2), true) << "If it is currently player 2, it should return true when there is a \"horizontal streak\" or when all the values of gameBoard[2][value] = \"O\"";
}
// Vertical Streak
TEST(TTT, VerticalStreak){
  const std::vector<std::vector<std::string>> verStreak1 = {{"X", "_", "_"}, {"X", "_", "_"}, {"X", "_", "_"}};
  const std::vector<std::vector<std::string>> verStreak2 = {{"_", "O", "_"}, {"_", "O", "_"}, {"_", "O", "_"}};
  const std::vector<std::vector<std::string>> verStreak3 = {{"O", "O", "X"}, {"O", "X", "X"}, {"X", "O", "X"}};
  ASSERT_EQ(PlayerWonCheck(verStreak1, 1), true) << "If it is currently player 1, it should return true when there is a \"vertical streak\" or when all the values of gameBoard[value][0] = \"X\"";
  ASSERT_EQ(PlayerWonCheck(verStreak2, 2), true) << "If it is currently player 2, it should return true when there is a \"vertical streak\" or when all the values of gameBoard[value][1] = \"O\"";
  ASSERT_EQ(PlayerWonCheck(verStreak3, 1), true) << "If it is currently player 1, it should return true when there is a \"vertical streak\" or when all the values of gameBoard[value][2] = \"X\"";
}
// Diagonal Left
TEST(TTT, LeftDiagonalStreak){
  const std::vector<std::vector<std::string>> lefDStreak1 = {{"X", "_", "_"}, {"_", "X", "_"}, {"_", "_", "X"}};
  const std::vector<std::vector<std::string>> lefDStreak2 = {{"O", "X", "_"}, {"_", "O", "X"}, {"X", "O", "O"}};
  ASSERT_EQ(PlayerWonCheck(lefDStreak1, 1), true) << "If it is currently player 1, it should return true when there is a \"left to right diagonal streak\" or when [0][0], [1][1], [2][2] = \"X\"";
  ASSERT_EQ(PlayerWonCheck(lefDStreak2, 2), true) << "If it is currently player 2, it should return true when there is a \"left to right diagonal streak\" or when [0][0], [1][1], [2][2] = \"O\"";
}
// Diagonal Right
TEST(TTT, RightDiagonalStreak){
  const std::vector<std::vector<std::string>> rightDStreak1 = {{"_", "_", "X"}, {"_", "X", "_"}, {"X", "_", "_"}};
  const std::vector<std::vector<std::string>> rightDStreak2 = {{"X", "X", "O"}, {"_", "O", "X"}, {"O", "O", "_"}};
  ASSERT_EQ(PlayerWonCheck(rightDStreak1, 1), true) << "If it is currently player 1, it should return true when there is a \"right to left diagonal streak\" or when [0][2], [1][1], [2][0] = \"X\"";
  ASSERT_EQ(PlayerWonCheck(rightDStreak2, 2), true) << "If it is currently player 2, it should return true when there is a \"right to left diagonal streak\" or when [0][2], [1][1], [2][0] = \"O\"";
}
// Mix match one
TEST(TTT, MixMatchStreaks){
  const std::vector<std::vector<std::string>> mmHorStreak = {{"X", "O", "X"}, {"_", "_", "_"}, {"_", "_", "_"}}; // horizontal streak
  const std::vector<std::vector<std::string>> mmRigStreak = {{"O", "_", "_"}, {"X", "_", "_"}, {"O", "_", "_"}}; // verical streak
  const std::vector<std::vector<std::string>> mmLDStreak = {{"X", "_", "O"}, {"X", "X", "_"}, {"O", "_", "O"}}; // left diagonal streak
  const std::vector<std::vector<std::string>> mmRDStreak = {{"_", "_", "O"}, {"X", "X", "_"}, {"O", "_", "O"}}; // right diagonal streak
  // horizontal streak check
  ASSERT_EQ(PlayerWonCheck(mmHorStreak, 1), false) << "Make sure that your function only considers a horizontal streak occurance when there is a \"horizontal line\" composed of either X's or O's, no mix matching is allowed";
  ASSERT_EQ(PlayerWonCheck(mmHorStreak, 2), false) << "Make sure that your function only considers a horizontal streak occurance when there is a \"horizontal line\" composed of either X's or O's, no mix matching is allowed";
  // verical streak check
  ASSERT_EQ(PlayerWonCheck(mmRigStreak, 1), false) << "Make sure that your function only considers a vertical streak occurance when there is a \"vertical line\" composed of either X's or O's, no mix matching is allowed";
  ASSERT_EQ(PlayerWonCheck(mmRigStreak, 2), false) << "Make sure that your function only considers a vertical streak occurance when there is a \"vertical line\" composed of either X's or O's, no mix matching is allowed";
  // left diagonal streak check
  ASSERT_EQ(PlayerWonCheck(mmLDStreak, 1), false) << "Make sure that your function only considers a diagonal streak occurance when there is a \"left to right line\" composed of either X's or O's, no mix matching is allowed";
  ASSERT_EQ(PlayerWonCheck(mmLDStreak, 2), false) << "Make sure that your function only considers a diagonal streak occurance when there is a \"left to right line\" composed of either X's or O's, no mix matching is allowed";
  // right diagonal streak check
  ASSERT_EQ(PlayerWonCheck(mmRDStreak, 1), false) << "Make sure that your function only considers a diagonal streak occurance when there is a \"right to left line\" composed of either X's or O's, no mix matching is allowed";
  ASSERT_EQ(PlayerWonCheck(mmRDStreak, 2), false) << "Make sure that your function only considers a diagonal streak occurance when there is a \"right to left line\" composed of either X's or O's, no mix matching is allowed";
}
// No streaks tie
TEST(TTT, NoStreakTie){
  const std::vector<std::vector<std::string>> tieStreak1 = {{"X", "O", "X"}, {"X", "O", "X"}, {"O", "X", "O"}};
  const std::vector<std::vector<std::string>> tieStreak2 = {{"X", "X", "O"}, {"O", "O", "X"}, {"X", "O", "X"}};
  const std::vector<std::vector<std::string>> tieStreak3 = {{"O", "X", "O"}, {"O", "X", "X"}, {"X", "O", "X"}};
  ASSERT_EQ(PlayerWonCheck(tieStreak1, 1), false) << "Your function should not return true if there is a tie";
  ASSERT_EQ(PlayerWonCheck(tieStreak3, 1), false) << "Your function should not return true if there is a tie";
  ASSERT_EQ(PlayerWonCheck(tieStreak2, 2), false) << "Your function should not return true if there is a tie";
  ASSERT_EQ(PlayerWonCheck(tieStreak3, 2), false) << "Your function should not return true if there is a tie";
}
// console log tests for all three streaks
TEST(TTT, CorrectDisplay){
  const std::vector<std::vector<std::string>> horStreak = {{"X", "X", "X"}, {"_", "_", "_"}, {"_", "_", "_"}};
  const std::vector<std::vector<std::string>> verStreak = {{"_", "O", "_"}, {"_", "O", "_"}, {"_", "O", "_"}};
  const std::vector<std::vector<std::string>> lefDStreak = {{"O", "X", "_"}, {"_", "O", "X"}, {"X", "O", "O"}};
  const std::vector<std::vector<std::string>> rightDStreak = {{"_", "_", "X"}, {"_", "X", "_"}, {"X", "_", "_"}};

  testing::internal::CaptureStdout();
  PlayerWonCheck(horStreak, 1);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  PlayerWonCheck(verStreak, 2);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  PlayerWonCheck(lefDStreak, 2);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  PlayerWonCheck(rightDStreak, 1);
  std::string output4 = testing::internal::GetCapturedStdout();


  ASSERT_THAT(output1, "Player 1 has won horizontally!\n") << "Make sure that you are displaying the current player and what streak they have properly before returning true in the function PlayerWonCheck";
  ASSERT_THAT(output2, "Player 2 has won vertically!\n") << "Make sure that you are displaying the current player and what streak they have properly before returning true in the function PlayerWonCheck";
  ASSERT_THAT(output3, "Player 2 has won diagonally!\n") << "Make sure that you are displaying the current player and what streak they have properly before returning true in the function PlayerWonCheck";
  ASSERT_THAT(output4, "Player 1 has won diagonally!\n") << "Make sure that you are displaying the current player and what streak they have properly before returning true in the function PlayerWonCheck";
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--noskip") {
      skip = false;
    }
  }
  if (skip) {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}

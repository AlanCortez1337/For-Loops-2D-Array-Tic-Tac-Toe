#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"

#include "../../game.h"
#include <vector>

using ::testing::HasSubstr;
// TESTS
// Basic check to make sure the program is not identifying a blank or "_" as a
// player's move
TEST(TTT, BlankBoard) {
  const std::vector<std::vector<std::string>> blankBoard = {
      {"_", "_", "_"}, {"_", "_", "_"}, {"_", "_", "_"}};
  ASSERT_FALSE(PlayerWonCheck(blankBoard, 1))
      << "There might be a problem where your program attributes the blank "
         "spaces as a streak.";
  ASSERT_FALSE(PlayerWonCheck(blankBoard, 2))
      << "There might be a problem where your program attributes the blank "
         "spaces as a streak.";
}
// Basic check to make sure program identifies a horizontal streak
TEST(TTT, HorizontalStreak) {
  const std::vector<std::vector<std::string>> horStreak1 = {
      {"X", "X", "X"}, {"_", "_", "_"}, {"_", "_", "_"}};
  const std::vector<std::vector<std::string>> horStreak2 = {
      {"_", "_", "_"}, {"O", "O", "O"}, {"_", "_", "_"}};
  const std::vector<std::vector<std::string>> horStreak3 = {
      {"X", "X", "O"}, {"O", "X", "X"}, {"O", "O", "O"}};
  ASSERT_TRUE(PlayerWonCheck(horStreak1, 1))
      << "If it is currently player 1, it should return true when there is a "
         "\"horizontal streak\" or when all the values of "
         "gameBoard[top_row][column] = \"X\".";
  ASSERT_TRUE(PlayerWonCheck(horStreak2, 2))
      << "If it is currently player 2, it should return true when there is a "
         "\"horizontal streak\" or when all the values of "
         "gameBoard[middle_row][column] = \"O\".";
  ASSERT_TRUE(PlayerWonCheck(horStreak3, 2))
      << "If it is currently player 2, it should return true when there is a "
         "\"horizontal streak\" or when all the values of "
         "gameBoard[bottom_row][column] = \"O\".";
}
// Basic check to make sure program identifies a vertical streak
TEST(TTT, VerticalStreak) {
  const std::vector<std::vector<std::string>> verStreak1 = {
      {"X", "_", "_"}, {"X", "_", "_"}, {"X", "_", "_"}};
  const std::vector<std::vector<std::string>> verStreak2 = {
      {"_", "O", "_"}, {"_", "O", "_"}, {"_", "O", "_"}};
  const std::vector<std::vector<std::string>> verStreak3 = {
      {"O", "O", "X"}, {"O", "X", "X"}, {"X", "O", "X"}};
  ASSERT_TRUE(PlayerWonCheck(verStreak1, 1))
      << "If it is currently player 1, it should return true when there is a "
         "\"vertical streak\" or when all the values of "
         "gameBoard[row][left_column] = \"X\".";
  ASSERT_TRUE(PlayerWonCheck(verStreak2, 2))
      << "If it is currently player 2, it should return true when there is a "
         "\"vertical streak\" or when all the values of "
         "gameBoard[row][middle_column] = \"O\".";
  ASSERT_TRUE(PlayerWonCheck(verStreak3, 1))
      << "If it is currently player 1, it should return true when there is a "
         "\"vertical streak\" or when all the values of "
         "gameBoard[row][right_column] = \"X\".";
}
// Basic check to make sure program identifies a left to right diagaonal streak
TEST(TTT, LeftDiagonalStreak) {
  const std::vector<std::vector<std::string>> lefDStreak1 = {
      {"X", "_", "_"}, {"_", "X", "_"}, {"_", "_", "X"}};
  const std::vector<std::vector<std::string>> lefDStreak2 = {
      {"O", "X", "_"}, {"_", "O", "X"}, {"X", "O", "O"}};
  ASSERT_TRUE(PlayerWonCheck(lefDStreak1, 1))
      << "If it is currently player 1, it should return true when there is a "
         "\"left to right diagonal streak\" or when the top left and its "
         "opposite corner makes a \"diagonal line\".";
  ASSERT_TRUE(PlayerWonCheck(lefDStreak2, 2))
      << "If it is currently player 2, it should return true when there is a "
         "\"left to right diagonal streak\" or when the top left and its "
         "opposite corner makes a \"diagonal line\".";
}
// Basic check to make sure program identifies a right to left diagaonal streak
TEST(TTT, RightDiagonalStreak) {
  const std::vector<std::vector<std::string>> rightDStreak1 = {
      {"_", "_", "X"}, {"_", "X", "_"}, {"X", "_", "_"}};
  const std::vector<std::vector<std::string>> rightDStreak2 = {
      {"X", "X", "O"}, {"_", "O", "X"}, {"O", "O", "_"}};
  ASSERT_TRUE(PlayerWonCheck(rightDStreak1, 1))
      << "If it is currently player 1, it should return true when there is a "
         "\"right to left diagonal streak\" or when the top right and its "
         "opposite corner makes a \"diagonal line\".";
  ASSERT_TRUE(PlayerWonCheck(rightDStreak2, 2))
      << "If it is currently player 2, it should return true when there is a "
         "\"right to left diagonal streak\" or when the top right and its "
         "opposite corner makes a \"diagonal line\".";
}
// This is to make sure the program is not registering that a "line" composed of
// X and O's as a streak
TEST(TTT, MixMatchStreaks) {
  const std::vector<std::vector<std::string>> mmHorStreak = {
      {"X", "O", "X"},
      {"_", "_", "_"},
      {"_", "_", "_"}}; // mix-matched horizontal streak
  const std::vector<std::vector<std::string>> mmRigStreak = {
      {"O", "_", "_"},
      {"X", "_", "_"},
      {"O", "_", "_"}}; // mix-matched verical streak
  const std::vector<std::vector<std::string>> mmLDStreak = {
      {"X", "_", "O"},
      {"X", "X", "_"},
      {"_", "_", "O"}}; // mix-matched left to right diagonal streak
  const std::vector<std::vector<std::string>> mmRDStreak = {
      {"_", "_", "O"},
      {"X", "X", "_"},
      {"O", "_", "O"}}; // mix-matched right to left diagonal streak
  // mix-matched horizontal streak check
  ASSERT_FALSE(PlayerWonCheck(mmHorStreak, 1))
      << "Make sure that your function only considers a horizontal streak "
         "occurance when there is a \"horizontal line\" composed of only X's "
         "or O's, no mix matching is allowed.";
  ASSERT_FALSE(PlayerWonCheck(mmHorStreak, 2))
      << "Make sure that your function only considers a horizontal streak "
         "occurance when there is a \"horizontal line\" composed of only X's "
         "or O's, no mix matching is allowed.";
  // mix-matched verical streak check
  ASSERT_FALSE(PlayerWonCheck(mmRigStreak, 1))
      << "Make sure that your function only considers a vertical streak "
         "occurance when there is a \"vertical line\" composed of only X's or "
         "O's, no mix matching is allowed.";
  ASSERT_FALSE(PlayerWonCheck(mmRigStreak, 2))
      << "Make sure that your function only considers a vertical streak "
         "occurance when there is a \"vertical line\" composed of only X's or "
         "O's, no mix matching is allowed.";
  // mix-matched left to right diagonal streak check
  ASSERT_FALSE(PlayerWonCheck(mmLDStreak, 1))
      << "Make sure that your function only considers a diagonal streak "
         "occurance when there is a \"left to right diagonal line\" composed "
         "of only X's or O's, no mix matching is allowed.";
  ASSERT_FALSE(PlayerWonCheck(mmLDStreak, 2))
      << "Make sure that your function only considers a diagonal streak "
         "occurance when there is a \"left to right diagonal line\" composed "
         "of only X's or O's, no mix matching is allowed.";
  // mix-matched right to left diagonal streak check
  ASSERT_FALSE(PlayerWonCheck(mmRDStreak, 1))
      << "Make sure that your function only considers a diagonal streak "
         "occurance when there is a \"right to left diagonal line\" composed "
         "of only X's or O's, no mix matching is allowed.";
  ASSERT_FALSE(PlayerWonCheck(mmRDStreak, 2))
      << "Make sure that your function only considers a diagonal streak "
         "occurance when there is a \"right to left diagonal line\" composed "
         "of only X's or O's, no mix matching is allowed.";
}
// This test is mainly to check if the programmer did not change anything
// outside of PlayerWonCheck
TEST(TTT, NoStreakTie) {
  const std::vector<std::vector<std::string>> tieStreak1 = {
      {"X", "O", "X"}, {"X", "O", "X"}, {"O", "X", "O"}};
  const std::vector<std::vector<std::string>> tieStreak2 = {
      {"X", "X", "O"}, {"O", "O", "X"}, {"X", "O", "X"}};
  const std::vector<std::vector<std::string>> tieStreak3 = {
      {"O", "X", "O"}, {"O", "X", "X"}, {"X", "O", "X"}};
  ASSERT_FALSE(PlayerWonCheck(tieStreak1, 1))
      << "Your function should not return true if there is a tie, remember to "
         "not modify anything outside of PlayerWonCheck.";
  ASSERT_FALSE(PlayerWonCheck(tieStreak2, 2))
      << "Your function should not return true if there is a tie, remember to "
         "not modify anything outside of PlayerWonCheck.";
  ASSERT_FALSE(PlayerWonCheck(tieStreak3, 1))
      << "Your function should not return true if there is a tie, remember to "
         "not modify anything outside of PlayerWonCheck.";
  ASSERT_FALSE(PlayerWonCheck(tieStreak3, 2))
      << "Your function should not return true if there is a tie, remember to "
         "not modify anything outside of PlayerWonCheck.";
}
// This is to check if it is correctly outputting what is meant to show the
// player
TEST(TTT, CorrectDisplay) {
  const std::vector<std::vector<std::string>> horStreak = {
      {"X", "X", "X"}, {"_", "_", "_"}, {"_", "_", "_"}};
  const std::vector<std::vector<std::string>> verStreak = {
      {"_", "O", "_"}, {"_", "O", "_"}, {"_", "O", "_"}};
  const std::vector<std::vector<std::string>> lefDStreak = {
      {"O", "X", "_"}, {"_", "O", "X"}, {"X", "O", "O"}};
  const std::vector<std::vector<std::string>> rightDStreak = {
      {"_", "_", "X"}, {"_", "X", "_"}, {"X", "_", "_"}};
  // https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest/33186201#33186201
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

  ASSERT_THAT(output1, "Player 1 has won horizontally!\n")
      << "Make sure that you are displaying the current player and the correct "
         "streak before returning true in the function: \"PlayerWonCheck\" "
         "(More details in README.md).";
  ASSERT_THAT(output2, "Player 2 has won vertically!\n")
      << "Make sure that you are displaying the current player and the correct "
         "streak before returning true in the function: \"PlayerWonCheck\" "
         "(More details in README.md).";
  ASSERT_THAT(output3, "Player 2 has won diagonally!\n")
      << "Make sure that you are displaying the current player and the correct "
         "streak before returning true in the function: \"PlayerWonCheck\" "
         "(More details in README.md).";
  ASSERT_THAT(output4, "Player 1 has won diagonally!\n")
      << "Make sure that you are displaying the current player and the correct "
         "streak before returning true in the function: \"PlayerWonCheck\" "
         "(More details in README.md).";
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

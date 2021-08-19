# For Loops in 2D Array: Tic-Tac-Toe
## Goal
We have provided the bulk of the program, you are able to compile it and run it to play the game. However, as you might notice the game does not end if a player has a vertical, horizontal, or diagonal streak. Today your goal will be to navigate through a two-dimensional vector in order to see if a player has won vertically, horizontally, or diagonally.

Feel free to browse the finished code in ``main.cc`` and ``game.h``, what you will be completing is the function: *PlayerWonCheck* in ``game.cc``.
## Refresher on 2D vectors
Before continuing it is a good idea to get a refresher on how a two-dimensional vector works.

For a 2D vector the first square bracket would tell the compiler which sub-vector inside the main vector we should be viewing. While the second square bracket is meant to look at the data inside of the current sub-vector.

For example:
```
#include <iostream>
#include <vector>

int main(){
  std::vector<std::vector<int>> 2dVect = {{1,2,3}, {4,5,6}, {7,8,9}};

  std::cout << "The first value in the second vector is: " << 2dVect[1][0] << std::endl;
  std::cout << "The second value in the first vector is: " << 2dVect[0][1] << std::endl;
  std::cout << "The third value in the third vector is: " << 2dVect[2][2] << std::endl;
  return 0;
}
```
This would return:
```
The first value in the second vector is: 4
The second value in the first vector is: 2
The third value in the third vector is: 9
```
## ``PlayerWonCheck`` details
This function will be continuously called each time a player inputs their move in order to check if they won. ``PlayerWonCheck`` is a ``bool`` that should return **true** if a player has a streak or **false** if they have not won yet *(do no worry about if there is a tie)*. As well as, a print statement saying a mix of the following:
```
Player 1 has won horizontally!
Player 2 has won vertically!
Player 1 has won diagonally!
```
The function's parameters need to include *two things*: first a two-dimensional vector *(vector inside of a vector)* with the main data type being a ``std::string``, and then an integer to store the player number of the current active player.

To break this problem down further we are going to divide the following section into two parts:
1. Horizontal and Vertical Streaks
2. Diagonal Streaks

### Horizontal and vertical streaks
Right now let us worry about how to find a ``Horizontal`` streak. When looking for this streak an obvious conclusion is that a horizontal streak is a straight line from left to right or vice versa. But how does this translate to c++? Looking at the example 2D vector above, it just shows a fairly unreadable array of values for us: ``{{1,2,3}, {4,5,6}, {7,8,9}}``.
However, we can make this more readable by reordering the way it *visually* looks, for example:
```
{
  {1,2,3},
  {4,5,6},
  {7,8,9}
}
```
Now, we are able to see a familiar 3x3 grid which a traditional Tic-Tac-Toe game is played on. In this format we can easily tell where a specific point is on the grid by calling a vector at \["x"]["y"] *(where x is left to right and y is top to bottom)* or \["rows"]["columns"]\. With that information, consider what might be a horizontal and vertical line on the 2D Vector using square brackets to see what a value is at a point.
Horizontal Example:
```
{
  {X,X,X},       X X X
  {O,O,_},  or   O O _
  {_,_,_}        _ _ _
}
```
Vertical Example:
```
{
  {X,O,O},       X O O
  {X,_,_},  or   X _ _
  {X,_,_}        X _ _
}
```
After that, remember to print the current player who won, the winning streak, and return true to make the program work properly.
### Diagonal streaks
Understanding how we found a horizontal or vertical streak, a diagonal will be a tad easier to understand. This can really just be condensed to check the opposite corners and the middle to see if a player has a winning streak.
For example:
```
{
  {X,O,O},       X O O
  {_,X,_},  or   _ X _
  {_,_,X}        _ _ X
}
```
This should print the statement:
```
Player 1 has won diagonally!
```
## Run the program

To manually test your code you can compile and run this program with:

```
clang++ -std=c++17 main.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
./main
```

*Note: you need a few additional flags on Mac which are not shown here.*

However, that's a lot to type, so we've included a shortcut to compile and create ``main``:

```
make build
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Completed ``game.cc``.
2. Compiled and manually ran the driver (``main``)
3. Manually checked for compilation and logical errors.
4. Ensured no errors on the unit test (`make test`).
5. Followed advice from the stylechecker (`make stylecheck`).
6. Followed advice from the formatchecker to improve code readability (`make formatcheck`).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission

We recommend pushing to Github frequently to back up your work.

# For Loops in 2D Array: Tic-Tac-Toe
## Goal
We have provided the core of the program, you are actually able to compile it and run it to play the game. However, as you might notice the game does not end if a player has a vertical, horizontal, or diagonal streak. Today your goal will be to navigate through a two-dimensional vector in order to see if a player has won vertically, horizontally, or diagonally.

``main.cc``, ``game.h`` are already completed, you will be completing the function *PlayerWonCheck* in ``game.cc``.
## Refresher on 2D Vectors
Before continuing it is a good idea to get a refresher how a two-dimensional vector or in this example a grid will look.

In a traditional one-dimensional vector, we are able to get the value at the current index by using [] and inputting an integer inside signifying its location. Similarly if we were looking at a 2D vector, we would still use the first [] to signify location we are looking at. However, this time since we have a vector inside of a vector the first [] is telling the compiler which vector we are viewing. Then the second [] tells us the value inside of the second vector we want to return.
An example:
```
#include <iostream>
#include <vector>

int main(){
  std::vector<int> 2dVect = {{1,2,3}, {4,5,6}, {7,8,9}};

  std::cout << "The first value in the second vector is: " << 2dVect[1][0] << std::endl;
  std::cout << "The second value in the first vector is: " << 2dVect[0][1] << std::endl;
  std::cout << "The third value in the third vector is: " << 2dVect[2][2] << std::endl;
  return 0;
}
```
These would return:
```
The first value in the second vector is: 4
The second value in the first vector is: 2
The third value in the third vector is: 9
```
## ``game.cc``



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
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).

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

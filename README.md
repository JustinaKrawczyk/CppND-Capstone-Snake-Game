# CppND-Capstone-Snake-Game

This snake game has been developed as a project task in the context of [Udacity Nanodegree Program C++](https://github.com/udacity/CppND-Capstone-Snake-Game) and extended by a results list which is stored permanently in a file. In the beginning of very game the player is asked to type-in his name to the console. After typing the name in, the classical snake game is started. At the end of the game, the game result is compared to the other results in the list and the current ranking is calculated using the achieved score. After the calculation, a result list is shown on the console listing the five best player's. The player's name, his/her score and the achieved size of the snake is written to the permanently stored result file which is called ``` dbfile.txt ```.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Compile and run

* ```git clone https://github.com/JustinaKrawczyk/CppND-Capstone-Snake-Game``` into your workspace.
* ```cd CppND-Capstone-Snake-Game```
* ```mkdir build ```
* ```cd build ```
* ```cmake .. && make ```
* Run the game by running the executable ```./SnakeGame```.

## Rubric points position in source code

### Loops, functions, I/Os

| Criteria | Line | Class | Method |
| ---------|------|-------|--------|
| The project demonstrates an understanding of C++ functions and control structures. | 103 ff. | main.cpp | prepareResults |
| The project reads data from a file and process the data, or the program writes data to a file. | 65 ff. | results.cpp | readResults/writeResults |
| The project accepts user input and processes the input. | 48 ff. | results.cpp | waitForPlayerName |

### Object oriented programming

| Criteria | Line | Class | Method |
| ---------|------|-------|--------|
| Classes use appropriate access specifiers for class members. | 8 | e.g. players.h |
| Class constructors utilize member initialization lists. | 10 | players.h | Player |
| Classes encapsulate behavior. | 14 ff. | players.h | e.g. getName/ getAlias |
| Classes follow an appropriate inheritance hierarchy. | 14 ff. | players.h | setName/ getName/ getAlias |
| Overloaded functions allow the same function to operate on different parameters. | 7ff. | player.cpp | setName |
| Derived class functions override virtual base class functions. | 7 ff. | player.cpp | setName/ getName |
| Templates generalize functions in the project. | 19 ff. | main.cpp | writeDataToConsole |

### Memory management

| Criteria | Line | Class | Method |
| ---------|------|-------|--------|
| The project makes use of references in function declarations. | 92 | main.cpp | main |
| The project uses smart pointers instead of raw pointers. | 47 | results.h | resultsTable |

### Concurrency

| Criteria | Line | Class | Method |
| ---------|------|-------|--------|
| The project uses multithreading. | 50 + 70 | main.cpp | main |
| A promise and future is used in the project. | 48 ff. | main.cpp | main |
| A mutex or lock is used in the project. | 63 | main.cpp | main |
| A condition variable is used in the project. | 68 ff. | main.cpp | main |


## More information

[Udacity Nanodegree Program C++](https://github.com/udacity/CppND-Capstone-Snake-Game).

## License

[MIT](https://opensource.org/licenses/MIT)

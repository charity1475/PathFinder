[![Build Status](https://travis-ci.com/charity1475/messanger.io.svg?token=emDS5SVA99dbgxURt67q&branch=main)](https://travis-ci.com/charity1475/messanger.io) 
# Capstone Projects Repository.
# Building an OpenStreetMap Route Planner.

The aim of this project is to implement the A* search algorithm  to traverse the street map.
Given input grids from t file the program reads the maze's grids and compute the path from 
destination A to B. The program returns the maze and the path. Motion planning/Path planning is the
crucial part in autonomous navigation.

![alt text](https://github.com/charity1475/PathFinder/blob/master/resources/bestpath.png?raw=true)


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./main`.
   

# [Read More About A* Search](http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html)
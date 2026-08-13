# Bowling kata in C++

[![CI](https://github.com/Coding-Cuddles/bowling-cpp-kata/actions/workflows/main.yml/badge.svg)](https://github.com/Coding-Cuddles/bowling-cpp-kata/actions/workflows/main.yml)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

Implement ten-pin bowling scoring in C++17 with GoogleTest. Setup is complete
when the starter gutter-game test passes.

## Overview

This kata complements [Clean Code: Fundamentals, Ep. 5 - Form](https://cleancoders.com/episode/clean-code-episode-5).

In bowling, a player rolls a ball down a lane and tries to knock down as many
pins as possible. The game consists of ten frames, and in each frame, the
player has two opportunities (called rolls) to knock down as many pins as
possible.

If, after two rolls, at least one pin is still standing, it’s called an **open
frame**. The score for the frame is the total number of pins knocked down,
plus bonus points awarded for strikes or spares.

A **spare** is when the player knocks down all the pins in two rolls. If the
player gets a spare, the score for the frame is ten, plus the number of pins
knocked down on their next roll. If a spare is thrown in the tenth frame, the
player is awarded one more roll.

A **strike** is when the player knocks down all the pins in one roll. If the
player gets a strike, their score for the frame is ten, plus the number of pins
knocked down on their next two rolls. If a strike is thrown in the tenth frame,
the player is awarded two more rolls.

The final score is the total of all frame scores.

## Instructions

In this kata, you will write a class `BowlingGame` that calculates the score of
a ten-pin bowling game with two methods:

1. `void roll(int pins)` is called each time the player rolls a ball, with
   `pins` representing the number of pins knocked down in the current roll;
2. `int score()` returns the score calculated using the above rules.

## Examples

### Spare with a bonus

Here is an example of a game where the player gets a bonus after rolling a
spare:

```cpp
game.roll(7);
game.roll(3);  // Spare: 7 + 3 + 6 (bonus) = 16
game.roll(6);
game.roll(2);  // Open frame: 6 + 2 = 8

assert(game.score() == 24);
```

In this example, the player got a spare, which is ten plus the next roll. The
next roll (from the second frame) was a 6, so the value of the first frame is 16.
The second frame is worth exactly the number of pins the player knocked
down. Added to 16, it gives a total of 24.

### Perfect game

Here is an example of a game where the player gets the maximum score:

```cpp
for (int i = 0; i < 12; ++i)
    game.roll(10);

assert(game.score() == 300);
```

In this example, the player gets 12 strikes in a row, the maximum number of
strikes possible in a game. Each strike is worth 10 points, plus the number of
pins knocked down on the next two rolls, resulting in 300 points.

## Prerequisites

Required:

- [Git](https://git-scm.com/downloads)
- A compiler with C++17 support. Choose one:
  - [GCC](https://gcc.gnu.org/) 10+ on Linux
  - [LLVM Clang](https://llvm.org/) 14+ on Linux
  - [Apple Clang](https://developer.apple.com/xcode/) 17+ on macOS
  - [MSVC](https://visualstudio.microsoft.com/) 2022 on Windows
- [CMake 3.24 or later](https://cmake.org)

Optional:

- [GNU Make](https://www.gnu.org/software/make/), for shorter commands. Every
  required task also has direct CMake and CTest commands. Make may be
  unavailable on Windows.

You do not need to install GoogleTest separately. CMake finds an installed
copy or downloads the pinned release when needed.

## Set up the kata

1. Clone the repository:

   ```console
   git clone https://github.com/Coding-Cuddles/bowling-cpp-kata.git
   ```

2. Enter the repository directory:

   ```console
   cd bowling-cpp-kata
   ```

3. Run the starter test. Use Make when it is installed:

   ```console
   make test
   ```

   Otherwise, use CMake and CTest directly:

   ```console
   cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
   cmake --build build --config Debug
   ctest --test-dir build --build-config Debug --output-on-failure
   ```

The first run may download and build GoogleTest. CTest should report
`100% tests passed`.

If a command reports a missing compiler or CMake, install that prerequisite
and run the setup commands again.

Setup is complete when CTest reports `100% tests passed`.

## Work on the kata

1. Add the next scoring example to `test_bowling.cpp`.

2. Implement the required behavior in `bowling.h`.

3. Run the tests. Use Make when it is installed:

   ```console
   make test
   ```

   Otherwise, use CMake and CTest directly:

   ```console
   cmake --build build --config Debug
   ctest --test-dir build --build-config Debug --output-on-failure
   ```

   Continue when CTest reports `100% tests passed`.

## Make command reference

Make is optional. Run `make` or `make help` to list these commands in the
terminal.

| Command             | Result                                    |
| ------------------- | ----------------------------------------- |
| `make all`          | Build and run the test suite              |
| `make help`         | Show the Make command reference           |
| `make build`        | Configure and build without running tests |
| `make test`         | Build and run the test suite              |
| `make format`       | Format tracked C++ and header files       |
| `make format-check` | Check formatting without changing files   |
| `make clean`        | Remove generated build artifacts          |

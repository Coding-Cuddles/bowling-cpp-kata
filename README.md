# Bowling C++ Kata

[![Run on Replit](https://replit.com/badge/github/Coding-Cuddles/bowling-cpp-kata)](https://replit.com/new/github/Coding-Cuddles/bowling-cpp-kata)

## Overview

This kata complements [Clean Code: Fundamentals, Ep. 5 - Form](https://cleancoders.com/episode/clean-code-episode-5).

In bowling, a player rolls a ball down a lane and tries to knock down as many pins as possible. The game consists of ten frames, and in each frame the player has two opportunities (called rolls) to knock down as many pins as possible. The score for the frame is the total number of pins knocked down, plus any bonus points awarded for strikes or spares.

A *spare* is when the player knocks down all of the pins in two rolls. A *strike* is when the player knocks down all of the pins in one roll. If the player gets a strike, their score for the frame is 10 plus the number of pins knocked down on their next two rolls. If the player gets a spare, their score for the frame is 10 plus the number of pins knocked down on their next roll.

The final score is the total of all frame scores.

## Instructions

In this kata, you will write a class `Game` that calculates the score of a game of ten-pin bowling that has two methods:

1. `void roll(int)` is called each time the player rolls a ball, the argument is the number of pins knocked down;
2. `int score()` returns the total score for that game.

## Usage

You can import this project into [Replit](https://replit.com),
and it will handle all dependencies automatically.

### Prerequisites

* [CMake 3.19+](https://cmake.org)
* [Ninja](https://ninja-build.org)
* [GTest](https://github.com/google/googletest)

### Build

```console
make
```

### Run main

```console
make run
```

### Run tests

```console
make test
```

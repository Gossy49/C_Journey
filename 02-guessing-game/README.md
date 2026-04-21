# Guessing Game

A simple number-guessing game written in C. The computer picks a random 
number between 1 and 100, and the player has a limited number of guesses 
depending on their chosen difficulty level.

## How to build and run

gcc guessing_game.c -o guessing_game
./guessing_game

## How it works

- User selects a difficulty: easy (10 tries), medium (5 tries), hard (3 tries)
- If an invalid difficulty is entered three times, the game defaults to medium
- The computer picks a random number between 1 and 100
- After each guess, the game gives a "too high" / "too low" hint
- Game ends when the user guesses correctly or runs out of tries

## Concepts practiced

- `while` and `if/else` control flow
- Functions with parameters (`hint()`)
- String comparison with `strcmp` from `<string.h>`
- Random numbers with `rand()` and `srand()` from `<stdlib.h>`
- Input validation with `scanf` return values
- Clearing the input buffer with `getchar()`
- `bool` from `<stdbool.h>`

## Known limitations

- `scanf("%s", difficulty)` can overflow the buffer if the user types more 
  than 9 characters — fixing this is on the TODO list
- No "play again" option after a round ends
- Difficulty input is case-sensitive ("Easy" is not recognized as "easy")

## What I'd do differently next time

- Use `fgets` instead of `scanf` for string input to avoid buffer overflow
- Extract the difficulty-to-tries mapping into its own function
- Add a play-again loop at the end
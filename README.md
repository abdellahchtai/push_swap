# push_swap

push_swap is an implementation of a sorting algorithm to arrange a stack of integers in ascending order with the use of two stacks. The project adheres to specific constraints and optimizations to achieve sorting with minimal operations.

## Table of Contents
- [Overview](#overview)
- [How it Works](#how-it-works)
- [Features](#features)
- [Bonus](#bonus)
- [How to Compile](#how-to-compile)
- [Usage](#usage)
- [Acknowledgments](#acknowledgments)

## Overview
This project is part of the 42 school curriculum. You are tasked with sorting a stack of integers using constrained operations on two stacks:
- **Stack `a`:** Initially filled with the unsorted integers.
- **Stack `b`:** Initially empty.

You can use the following operations:
- Push (`pa`, `pb`)
- Swap (`sa`, `sb`, `ss`)
- Rotate (`ra`, `rb`, `rr`)
- Reverse rotate (`rra`, `rrb`, `rrr`)

The goal is to sort the integers in Stack `a` with the fewest possible moves.

## How it Works
The program works as follows:
1. The input integers are validated and parsed.
2. The main algorithm selects the most efficient series of operations to sort the integers.
3. After sorting, the stack is checked to ensure it’s correctly ordered.

## Features
- Compliant with strict memory and performance constraints.
- Handles duplicate detection and invalid inputs.
- Provides an efficient solution to sorting within the above limits.

## Bonus
The project includes an additional program called the `checker`. This bonus utility validates the sequence of operations:
1. It reads a list of integers and the set of sorting operations performed by `push_swap`.
2. It checks whether the operations sort the stack correctly.
3. Outputs:
   - **OK:** If the stack is sorted correctly.
   - **KO:** If the stack remains incorrectly ordered.
   - **Error:** If invalid inputs or operations are provided.

The bonus consists of multiple source files under names such as `checker_bonus*.c` and includes functionality for list management, input handling, and stack checking.

## How to Compile
To build the project:

### Main Program
```bash
make
```
This will create the main `push_swap` binary.

### Bonus
```bash
make bonus
```
This will compile the `checker` bonus binary.

### Clean Up
To remove all binary files:
```bash
make clean
```
To remove binaries and compiled object files:
```bash
make fclean
```

## Usage
### Main Program
Run the `push_swap` program:
```bash
./push_swap [list of integers]
```
Example:
```bash
./push_swap 2 1 3 6 5 8
```

### Bonus - Checker
Run the `checker` program:
```bash
./checker [list of integers]
```
Example:
```bash
echo "pb\nra\npa" | ./checker 1 2 3
```
Example Output:
```
OK
or
KO
or
Error
```

## Acknowledgments
This project was completed by abchtaib as part of the 42 school curriculum.

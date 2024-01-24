# CSE102 Assignment #10 - Tower of Hanoi

## Overview

This assignment involves implementing a non-recursive solution to the Tower of Hanoi problem using stacks. The Tower of Hanoi is a mathematical puzzle with three poles and a stack of disks of different sizes. The goal is to move the entire stack to another pole, following two rules: a larger disk cannot be placed onto a smaller one, and only one disk can be moved at a time.

## Instructions

### Stack Implementation

The provided code includes a stack data structure with functions for initialization, pushing, and popping elements. The main objective is to use this stack to implement a non-recursive Tower of Hanoi solver. The stack uses a dynamic array that grows and shrinks by `STACK_BLOCK_SIZE` entries.

### Tower of Hanoi Solver

Your task is to implement a non-recursive solution for the Tower of Hanoi problem using the stack. The solver should be able to handle towers of any size.

### Functions

1. `int push(stack *s, data_type d)`: Pushes an element onto the stack.
2. `data_type pop(stack *s)`: Pops an element from the stack.
3. `stack *init_return()`: Initializes an empty stack and returns a pointer to it.
4. `int init(stack *s)`: Initializes a stack and returns 1 if successful.

## Usage

1. **Compilation:**
    ```bash
    $ make clean     # Remove compilation results and intermediate files
    $ make compile   # Compile the code
    ```

2. **Running the Program:**
    ```bash
    $ make run       # Run the code along with any parameters needed
    ```

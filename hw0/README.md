# CSE102 Assignment #0 - Fraction Arithmetic

## Overview

This assignment introduces you to C language basics, development environments, and makefiles. You will perform basic arithmetic operations on fractional numbers, and the goal is to familiarize yourself with coding in C and using makefiles.

## Project Structure

The project files are provided in the attached ZIP file (`hw0_src`). You are expected to modify two files:

1. **main.c:** In the `main` function, read two fractional numbers and perform addition, subtraction, multiplication, and division using the functions provided in `utils.h`.

2. **utils.c:** Complete four functions in this file to achieve the correct functionality. Note that after arithmetic operations, fractions may need to be simplified by finding the greatest common divisor (GCD) of two integers.

## How to Compile and Run

1. **Compilation:**
    ```bash
    $ make clean     # Remove compilation results and intermediate files
    $ make compile   # Compile the code
    ```

2. **Running the Program:**
    ```bash
    $ make run       # Run the code along with any parameters needed
    ```


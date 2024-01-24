# CSE102 Homework #1 - ATM System

## Overview

This C program implements a simple ATM system with three different functionalities: finding divisible numbers, creating a new customer account, and checking login and withdrawal capabilities. The program is divided into three parts, each focusing on a specific functionality.

## Part 1 - Finding Divisible Numbers

Given two integers X and Y and a third number Z, the program calculates the first integer (f_i) between X and Y that can be divided by Z. The program also calculates the Nth number divisible by Z, where N is specified by the user. The user is prompted for input, and the program handles the calculations.

### Example

Enter the first integer: 10
Enter the second integer: 20
Enter the divisor: 3
Output> The first integer between 10 and 20 divided by 3 is 12
Enter the number how many next: 2
Output> The 3rd integer between 10 and 20 divided by 3 is 18


### Function Prototypes

- `int find_divisible(int x, int y, int z)`
- `int find_nth_divisible(int n, int f_i, int z)`

## Part 2 - Creating a New Customer Account

The program validates the format of an entered identity number and creates a new customer account by saving the identity number and a 4-digit password to a file named `customeraccount.txt`.

### Function Prototype

- `int create_customer(char identity_number[], int password)`

## Part 3 - Checking Login and Withdrawal

The program checks the login credentials (identity number and password) against the `customeraccount.txt` file and calculates the withdrawable amount for a requested cash amount.

### Function Prototype

- `int check_login(char identity_number[], int password)`
- `int withdrawable_amount(float cash_amount)`


## How to Use

1. **Compilation:**
    ```bash
    $ make clean     # Remove compilation results and intermediate files
    $ make compile   # Compile the code
    ```

2. **Running the Program:**
    ```bash
    $ make run       # Run the code along with any required parameters
    ```
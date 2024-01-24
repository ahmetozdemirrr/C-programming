# CSE102 Homework #9 - Banking System

This is the ninth homework assignment for the CSE102 course, focusing on implementing a banking system in C. The assignment involves working with Structs, Unions, Recursive functions, and File operations.

## Assignment Overview

In this homework, students are required to create a simple banking system that allows for customer management, loan assignments, and loan calculations. The system uses a set of predefined data structures:

- **Person Union:** Contains personal information such as name, address, and phone number.
- **Loan Union:** Represents loan details, including amount, interest rate, and period.
- **BankAccount Struct:** Combines the Person and Loan unions to create a complete customer record.

## Functions

The following functions are required for the assignment:

1. `listCustomers()`: Lists all customers in the system.
2. `addCustomer()`: Adds a new customer and assigns loans.
3. `newLoan()`: Requests a new loan for a customer.
4. `calculateLoan(float amount, int period, float interestRate)`: Recursive function to calculate the loan.
5. `getReport()`: Prints out customer and loan details.

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


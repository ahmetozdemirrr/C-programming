Quadratic Equation Graph Drawer

This program allows users to draw the graph of a quadratic equation and save the coefficients and graph to files. The program is divided into three parts:

Part 0: Main Loop

- The program has an infinite loop that prompts the user to select an operation.
- The loop continues until the user chooses to exit.
- It provides warnings for improper input.

Part 1: Get Coefficients

- The program prompts the user to enter coefficients for a quadratic equation (three integers).
- These coefficients are written line by line to a file named "coefficients.txt."

Part 2: Draw Graph

- The program reads the coefficients from "coefficients.txt" and draws the graph on a 2D Cartesian plane.
- The graph is drawn within the range [-55, 55] for x values and [15, -15] for y values.
- Points on the graph are represented by "#" characters, while empty spaces are used for points not on the graph.
- Horizontal and vertical lines are represented by "-" and "|" characters.
- Numbers are printed under the x-axis and to the left of the y-axis to emphasize coordinates.
- Different colors are used to make the graph more understandable.

Part 3: Save Graph to File

- The program prints the same graph to a file named "graph.txt" without colors and without printing numbers.


How to Run the Program:

- Clone the repository: git clone https://github.com/your_username/your_repository.git
- Navigate to the program directory: cd your_repository
- Compile and run the program: gcc quadratic_graph_drawer.c -o graph_drawer && ./graph_drawer

Sample Usage:

1. Run the program and choose the desired operation.
2. Enter coefficients for the quadratic equation.
3. View the graph in the terminal and check the saved files.


Feel free to explore and customize the program based on your preferences and requirements. Enjoy graphing quadratic equations!
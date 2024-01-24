Overview

	This program serves as a geometric calculator, allowing the user to calculate the area, perimeter, and volume of various shapes. The supported shapes are Triangle, Quadrilateral, Circle, Pyramid, and Cylinder. Calculations can be performed using the enumerated types shapes and calculators to select the shape and calculation type.

Function Prototypes

1 - select_shape()

	* Returns the selected shape as an integer based on user input.

2 - select_calc()

	* Returns the selected calculator as an integer based on user input.

3 - calculate(int, int)

	* Takes the selected shape and calculator as parameters.
	* Utilizes switch-case structure to perform calculations based on the selected shape and calculator.

Enumerated Types

- Shapes
	
	* Triangle
	* Quadrilateral
	* Circle
	* Pyramid
	* Cylinder

- Calculators
	
	* Area
	* Perimeter
	* Volume

Important Formulas

~ Triangle
	
	* Heron's Formula for area: 𝐻𝑒𝑟𝑜𝑛'𝑠 𝑓𝑜𝑟𝑚𝑢𝑙𝑎 = √𝑠 ∗ (𝑠 − 𝑎) ∗ (𝑠 − 𝑏) ∗ (𝑠 − 𝑐)
	  𝑠 = (𝑎 + 𝑏 + 𝑐) / 2

~ Quadrilateral
	
	* Brahmagupta's Formula for area: 𝐵𝑟𝑎ℎ𝑚𝑎𝑔𝑢𝑝𝑡𝑎'𝑠 𝑓𝑜𝑟𝑚𝑢𝑙𝑎 = √(𝑠 − 𝑎) ∗ (𝑠 − 𝑏) ∗ (𝑠 − 𝑐) ∗ (𝑠 − 𝑑)
	  𝑠 = (𝑎 + 𝑏 + 𝑐 + 𝑑) / 2

~ Circle
	
	  𝐶𝑖𝑟𝑐𝑢𝑚𝑓𝑒𝑟𝑒𝑛𝑐𝑒 = 2 ∗ 𝜋 ∗ 𝑟
	  𝐴𝑟𝑒𝑎 = 𝜋 ∗ 𝑟^2

~ Pyramid
	  
	  𝑉𝑜𝑙𝑢𝑚𝑒 = (1 / 3) ∗ 𝑎^2 ∗ ℎ

~ Cylinder

	  𝑉𝑜𝑙𝑢𝑚𝑒 = 𝜋 ∗ 𝑟^2 ∗ ℎ
	  𝐵𝑎𝑠𝑒 𝑆𝑢𝑟𝑓𝑎𝑐𝑒 𝐴𝑟𝑒𝑎 = 𝜋 ∗ 𝑟^2
	  𝐿𝑎𝑡𝑒𝑟𝑎𝑙 𝑆𝑢𝑟𝑓𝑎𝑐𝑒 𝐴𝑟𝑒𝑎 = 2 ∗ 𝜋 ∗ 𝑟 ∗ 𝑟 + 𝜋 ∗ 𝑟 ∗ ℎ

Program Flow

1 - User selects a shape using select_shape().
2 - User selects a calculator (Area, Perimeter, or Volume) using select_calc().
3 - The calculate(int, int) function is called with the selected shape and calculator.
4 - The program performs calculations based on the selected shape and calculator.
5 - Incorrect inputs are handled with warning messages, and the program continues.

Compilation and Execution; To compile the program, execute the following commands:

	$ make
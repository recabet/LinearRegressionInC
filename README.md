Linear Regression in C
This project implements a simple linear regression model in C, including data initialization, training using gradient descent, and cost calculation.

Project Structure
linear_regression.h - Header file containing function declarations and global variable declarations.
linear_regression.c - Source file containing the implementation of the linear regression model.
main.c - Main file for initializing data, running the training process, and displaying the results

How to Compile and Run
Ensure you have a C compiler installed (e.g., gcc).

Save the files (linear_regression.h, linear_regression.c, main.c) in the same directory.

Open a terminal and navigate to the directory containing the files.

Compile the program using the following command:

gcc main.c linear_regression.c -o linear_regression

Run the compiled program:
./linear_regression

Explanation
Data Initialization: In main.c, example training data is defined and copied to a dynamically allocated train_data array.
Random Initialization: Coefficient k and bias b are initialized with random values.
Training: The train function uses gradient descent to optimize k and b to fit the training data.
Cost Calculation: The cost function calculates the mean squared error between the predicted and actual values.
Output: The optimized coefficient and bias are printed.



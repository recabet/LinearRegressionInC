# Linear Regression with Gradient Descent

This project implements linear regression using gradient descent in C. It includes functionalities to train a linear model based on provided data and calculate the optimal coefficients (slope) and bias (intercept).

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Functions](#functions)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Linear regression is a fundamental technique in statistics and machine learning used to model the relationship between variables. This project focuses on implementing linear regression using gradient descent, a common optimization algorithm for finding the minimum of a function.

## Installation

To use the linear regression library:

1. Clone the repository: git clone https://github.com/recabet/LinearRegressionInC.git

2. Navigate to the project directory: cd LinearRegerressionInC

3. Compile the code:
   gcc main.c linear_regression.c -o  -lm main


## Usage

- **train(coeff, bias, epsilon, rate, iterations)**: Trains the linear regression model with the provided initial coefficient (`coeff`) and bias (`bias`). `epsilon` is the small value used for numerical differentiation in gradient calculation, `rate` is the learning rate, and `iterations` is the number of iterations for gradient descent.

- **cost(coeff, bias)**: Computes the mean squared error (cost function) for the given coefficient and bias, comparing predicted values against actual data.

## Functions

### `float randf()`

Generates a random float between 0 and 1 using `rand()`.

### `float cost(float coeff, float bias)`

Calculates the mean squared error (MSE) cost function for a given coefficient and bias over the training data.

### `float* train(float coeff, float bias, const float epsilon, const float rate, size_t iterations)`

Performs gradient descent to optimize the coefficient and bias for the linear regression model. Returns an array of floats containing the optimized coefficient and bias.

## Example

Here's an example of how to use the linear regression library:

```c
#include "linear_regression.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
 srand(69); // Set random seed for reproducibility

 // Example starting weight and bias
 float initial_coefficient = randf() * 10;
 float initial_bias = randf() * 10;

 // Example data
 float example_data[][2] = {
     {0, 0},
     {1, 2.3},
     {2, 4.2},
     {3, 7.3},
     {4, 10.2}
 };

 // Set up training data
 train_size = sizeof(example_data) / sizeof(example_data[0]);
 train_data = malloc(train_size * sizeof(example_data[0]));
 if (train_data == NULL) 
 {
     fprintf(stderr, "Memory allocation failed\n");
     return 1;
 }
 // Copy example data to train_data
 for (size_t i = 0; i < train_size; i++) 
 {
     train_data[i][0] = example_data[i][0];
     train_data[i][1] = example_data[i][1];
 }

 // Train the model
 float* result = train(initial_coefficient, initial_bias, 1e-2, 1e-2, 5000);

 if (result != NULL) 
 {
     printf("Optimal Coefficient: %f, Optimal Bias: %f\n", result[0], result[1]);
     free(result);
 } 
 else 
 {
     fprintf(stderr, "Training failed\n");
 }

 free(train_data);

 return 0;
}


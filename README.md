# Linear Regression with Gradient Descent

This project implements linear regression using gradient descent in C. It includes functionalities to train a linear model based on provided data and calculate the optimal coefficients (slope) and bias (intercept).

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Linear regression is a fundamental technique in statistics and machine learning used to model the relationship between variables. This project focuses on implementing linear regression using gradient descent, a common optimization algorithm for finding the minimum of a function.

## Installation

To use the linear regression library:

1. Clone the repository
    ```
        git clone https://github.com/recabet/LinearRegressionInC.git
    ```
2. Navigate to the project directory:
    ```
        cd LinearRegerressionInC
    ```
3. Run the example use of the library
    ```
        make run
    ```

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

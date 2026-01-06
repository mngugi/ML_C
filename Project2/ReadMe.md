## ML in C – Linear Regression and Gradient Descent Example

A simple Machine Learning project in C demonstrating linear regression using arrays and loops. No external libraries are required.

This project is a foundation for learning ML concepts in C, including linear regression, gradient descent, and simple predictions.

### Table of Contents

Overview

Project Structure

Linear Regression Concept

Gradient Descent Concept

Code Explanation

Build and Run

Usage

Key Takeaways

Next Steps

## Overview

Linear regression is a supervised learning algorithm used to predict continuous values.

The linear regression formula:

```
y = m * x + b

Where:

m = slope

b = intercept
```
The goal is to find the best-fitting line through the data points using the least squares method or gradient descent.

### Project Structure

```
ML_C_Project/
├─ main.c # Entry point
├─ ml_utils.c # Helper functions (linear regression, gradient descent)
├─ ml_utils.h # Header file for ml_utils.c
├─ CMakeLists.txt # CMake build configuration
└─ build/ # Build output directory
```
### Linear Regression Concept

Predict y from x using a straight line.

Formula: y = m*x + b

Can compute m and b using least squares or gradient descent.

### Gradient Descent Concept

An iterative optimization algorithm to minimize the cost function.

For linear regression, cost function = mean squared error (MSE):

```
MSE = (1/n) * Σ(y_i - (m*x_i + b))^2

Update rules for each step:

m = m - α * (∂MSE/∂m)
b = b - α * (∂MSE/∂b)

Where α = learning rate
```
### Code Explanation
**main.c**

```
#include <stdio.h>
#include "ml_utils.h"

int main() {
double x[] = {1, 2, 3, 4, 5};
double y[] = {2, 4, 6, 8, 10};
int n = 5;

double m, b;  
linear_regression(x, y, n, &m, &b);  

printf("Linear Regression Result: y = %.2fx + %.2f\n", m, b);  

gradient_descent(x, y, n, 0.01, 1000, &m, &b);  
printf("Gradient Descent Result: y = %.2fx + %.2f\n", m, b);  

double test = 6;  
double prediction = m * test + b;  
printf("Prediction for x = %.2f : y = %.2f\n", test, prediction);  

return 0;  


}

ml_utils.h

#ifndef ML_UTILS_H
#define ML_UTILS_H

void linear_regression(const double *x, const double *y, int n, double *m, double *b);
void gradient_descent(const double *x, const double *y, int n, double lr, int epochs, double *m, double *b);

#endif

ml_utils.c

#include "ml_utils.h"

void linear_regression(const double *x, const double *y, int n, double *m, double *b) {
double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
for (int i = 0; i < n; i++) {
sum_x += x[i];
sum_y += y[i];
sum_xy += x[i] * y[i];
sum_x2 += x[i] * x[i];
}

*m = (n*sum_xy - sum_x*sum_y) / (n*sum_x2 - sum_x*sum_x);  
*b = (sum_y - (*m)*sum_x) / n;  


}

void gradient_descent(const double *x, const double *y, int n, double lr, int epochs, double *m, double *b) {
double m_curr = 0, b_curr = 0;

for (int i = 0; i < epochs; i++) {  
    double dm = 0, db = 0;  
    for (int j = 0; j < n; j++) {  
        double y_pred = m_curr * x[j] + b_curr;  
        dm += -2 * x[j] * (y[j] - y_pred);  
        db += -2 * (y[j] - y_pred);  
    }  
    m_curr -= lr * (dm / n);  
    b_curr -= lr * (db / n);  
}  

*m = m_curr;  
*b = b_curr;  


}
```
### Build and Run
```
CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(ML_C_Project C)
set(CMAKE_C_STANDARD 11)
add_executable(ml_app main.c ml_utils.c)
```
Build Commands

```
mkdir build
cd build
cmake ..
cmake --build .
./ml_app

Expected Output:

Linear Regression Result: y = 2.00x + 0.00
Gradient Descent Result: y = 2.00x + 0.00
Prediction for x = 6.00 : y = 12.00
```
### Usage

Modify x and y arrays in main.c for your dataset.

Call linear_regression() or gradient_descent() to compute m and b.

Use the results to predict new values.

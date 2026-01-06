Machine Learning in C – Linear Regression Exercise
1. Project Setup

We created a simple C project to implement linear regression.

Folder structure:

ML_C_Project/
├─ main.c         # Entry point
├─ ml_utils.c     # ML helper functions (linear regression)
├─ ml_utils.h     # Header file for ml_utils.c
├─ CMakeLists.txt # Build configuration for CMake
└─ build/         # Directory for compiled files

2. Linear Regression Concept

Linear regression predicts y based on x using the formula:

y = m*x + b


Where:

m = slope

b = intercept

The goal is to find m and b that minimize the difference between predicted and actual values.

3. Code Explanation
main.c
#include <stdio.h>
#include "ml_utils.h"

int main() {
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 4, 6, 8, 10};
    int n = 5;

    double m, b;
    linear_regression(x, y, n, &m, &b);

    printf("Linear Regression Result: y = %.2fx + %.2f\n", m, b);

    double test = 6;
    double prediction = m * test + b;
    printf("Prediction for x = %.2f : y = %.2f\n", test, prediction);

    return 0;
}


Explanation:

We define input arrays x and y.

We call linear_regression() to compute m and b.

We print the resulting linear equation and make a prediction for x = 6.

ml_utils.h
#ifndef ML_UTILS_H
#define ML_UTILS_H

void linear_regression(const double *x, const double *y, int n, double *m, double *b);

#endif


Explanation:

Header file declares the function linear_regression().

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


Explanation:

Computes sums required for slope (m) and intercept (b).

Uses the least squares method formula:

m = (N*Σ(xy) - Σx*Σy) / (N*Σ(x^2) - (Σx)^2)
b = (Σy - m*Σx) / N

4. Build with CMake

CMakeLists.txt:

cmake_minimum_required(VERSION 3.10)

project(ML_C_Project C)
set(CMAKE_C_STANDARD 11)

add_executable(ml_app main.c ml_utils.c)


Build commands:

mkdir build
cd build
cmake ..
cmake --build .
./ml_app


Output:

Linear Regression Result: y = 2.00x + 0.00
Prediction for x = 6.00 : y = 12.00

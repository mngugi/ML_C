
#include <stdio.h>
#include "ml_utils.h"

int main() {
    // Sample data
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

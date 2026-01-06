
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

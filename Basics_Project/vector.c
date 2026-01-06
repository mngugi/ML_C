#include <stdio.h>

double dot(const double *a, const double *b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}

int main(void) {
    double x[] = {1,2,3};
    double y[] = {4,5,6};
    printf("Dot product = %f\n", dot(x,y,3));
    return 0;
}

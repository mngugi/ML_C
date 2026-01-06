
#include <stdio.h>
#include "vector.h"

int main(void) {
    double a[] = {1, 2, 3};
    double b[] = {4, 5, 6};

    printf("%f\n", dot(a, b, 3));
    return 0;
}

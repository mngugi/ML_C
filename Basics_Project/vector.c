#include "vector.h"



double dot(const double *a, const doubl *b, int n){

    double sum = 0.0;
    for (int i =0; i < n; i++){
        sum += a[i] * b[i];
    }
     return sum;
}

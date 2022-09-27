#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPS 0.001

double sqrtRecur(double x, double p, double e) {
    if (fabs(p * p - x) < e) return p;
    return sqrtRecur(x, (p + x / p) / 2, e);
}

double sqrtLoop(double x, double p, double e) {
    while (fabs(p * p - x) >= e) {
        p = (p + x / p) / 2;
    }
    return p;
}

int main() {
    double a = (double)115;
    printf("%lf -> %lf", a, sqrtLoop(a, 1, EPS));
    return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(!a)
        printf("%.2lf\n", sqrt(c * c - b * b));
    if(!b)
        printf("%.2lf\n", sqrt(c * c - a * a));
    if(!c)
        printf("%.2lf\n", sqrt(a * a + b * b));
    return 0;
}

/*
3.00 4.00 0.00

3.00 0.00 5.00
*/
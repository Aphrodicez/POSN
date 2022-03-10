#include <stdio.h>
#include <math.h>

int main() {
    double r;
    scanf("%lf", &r);
    printf("%.2lf\n", acos(-1) * r * r);
    printf("%.2lf\n", 4 * acos(-1) * r * r / 3);
    return 0;
}
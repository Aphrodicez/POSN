#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    double r;
    scanf("%d %d", &a, &b);
    printf("%d\n", a * b);
    scanf("%lf", &r);
    printf("%.2lf", 2 * M_PI * r);
    return 0;
}
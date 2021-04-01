#include <stdio.h>
#include <math.h>

int main(){
    double r, pi = acos(-1), circle, sphere;
    scanf("%lf", &r);
    circle = pi * r * r;
    sphere = (4 * pi * r * r * r) / 3;
    printf("%.2lf\n%.2lf", circle, sphere);
    return 0;
}
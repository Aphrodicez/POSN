#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);    
    double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    
    // Heron's formula
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    // Equilateral triangle
    double side = sqrt(4 / sqrt(3) * area); // One side of the equilateral triangle
    double i = side;
    double j = side / 2;
    double k = sqrt(3) / 2 * side; // Height of the equilateral triangle (sin(60) * side)
    printf("%.2lf %.2lf %.2lf", i, j, k);
    return 0;
}
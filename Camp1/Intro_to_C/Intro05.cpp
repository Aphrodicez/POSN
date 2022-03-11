#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2, x3, y3, k;
    scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &k);
    double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double s = (a + b + c) / 2;
    printf("%.2lf\n", sqrt(s * (s - a) * (s - b) * (s - c)));
    printf("%.2lf\n", k * (a + b + c) + acos(-1) * k * k);
    return 0;
}

/*
0 0 3 0 0 4 2
*/
#include <stdio.h>
#include <math.h>

int main() {
    int r;
    scanf("%d", &r);
    printf("%.3lf\n", double(4 * acos(-1) * r * r));
    printf("%.3lf\n", (4.0 / 3) * acos(-1) * r * r * r);
    printf("%.3lf\n", acos(-1) * r * r);
    printf("%.3lf\n", 2.0 * acos(-1) * r);
    return 0;
}

/*
7
*/
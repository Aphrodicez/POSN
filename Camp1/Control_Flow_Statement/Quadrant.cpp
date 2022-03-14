#include <stdio.h>

int main() {
    int degree;
    scanf("%d", &degree);
    degree %= 360;
    degree += 360;
    degree %= 360;
    if(degree % 180 == 0)
        printf("x-axis\n");
    else if(degree % 180 == 90)
        printf("y-axis\n");
    else
        printf("%d\n", (degree - 1) / 90 + 1);
    return 0;
}

/*
315

180
*/
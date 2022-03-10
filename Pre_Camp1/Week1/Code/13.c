#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int sum = a + b + c;
    if(sum >= 80 && sum <= 100)
        printf("A\n");
    else if(sum >= 75)
        printf("B+\n");
    else if(sum >= 70)
        printf("B\n");
    else if(sum >= 65)
        printf("C+\n");
    else if(sum >= 60)
        printf("C\n");
    else if(sum >= 55)
        printf("D+\n");
    else if(sum >= 50)
        printf("D\n");
    else
        printf("F\n");
}
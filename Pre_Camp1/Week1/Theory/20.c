#include <stdio.h>

int main() {
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        for(j = n; j > i; j--)
            printf("-");
        for(j = 0; j < 2 * i + 1; j++)
            printf("*");
        for(j = n; j > i; j--)
            printf("-");
        printf("\n");
    }
    return 0;
}
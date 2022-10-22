#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        int i, j;
        for(i = 1; i <= 2 * n + 1; i++) {
            for(j = 1; j <= 2 * n + 1; j++) {
                if(i == 1 || j == 1)
                    printf("*"); // Top and Left border
                else if(i % 2 == 1 && j <= i)
                    printf("*"); // Vertical Edges
                else if(j % 2 == 1 && i <= j)
                    printf("*"); // Horizontal Edges
                else
                    printf("-");
            }
            printf("\n");
        }
    }
    return 0;
}
#include <stdio.h>

int a[20][20], b[20][20], ans[20][20];

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < r2; i++) {
        for(int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    if(r2 != c1) {
        printf("Can't Multiply.\n");
        return 0;
    }
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            ans[i][j] = 0;
            for(int k = 0; k < r2; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
2 3 3 2
4 5 -2
3 -4 1
-1 2
-5 -3
3 -6
*/
/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Brute Force + Math
    Status	: Accepted
*/

#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        int mid = (n + 1) / 2;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 1 || i == mid || j == 1)
                    printf("*");
                else if(i <= mid && j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++) {
                if(i == 1 || i == n || j == 1 || j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++) {
                if(i == 1 || i == mid || i == n)
                    printf("*");
                else if(i <= mid && j == 1)
                    printf("*");
                else if(i >= mid && j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++) {
                if(j == 1 || j == n || i == j)
                    printf("*");
                else
                    printf("-");
            }
            printf("\n");
        }
    }
    return 0;
}

/*
2
5
7
*/
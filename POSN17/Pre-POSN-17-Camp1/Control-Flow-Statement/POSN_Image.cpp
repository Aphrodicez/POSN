/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: For Loop
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int q;

    scanf("%d", &q);

    while(q--){

        int n;

        scanf("%d", &n);

        for(int i = 1; i <= 1; i++){
            for(int j = 1; j <= n; j++){
                printf("*");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                printf("*");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                printf("*");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("\n");
        }

        for(int i = 2; i <= (n / 2); i++){
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == i || j == 1 || j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("\n");
        }
        for(int i = (n / 2) + 1; i <= (n / 2) + 1; i++){
            for(int j = 1; j <= n; j++){
                printf("*");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                printf("*");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n || j == i)
                    printf("*");
                else    
                    printf("-");
            }
            printf("\n");
        }

        for(int i = (n / 2) + 2; i <= n - 1; i++){
            for(int j = 1; j <= n; j++){
                if(j == 1)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == n)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n || j == i)
                    printf("*");
                else
                    printf("-");
            }
            printf("\n");
        }

        for(int i = n; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j == 1)
                    printf("*");
                else
                    printf("-");
            }
            printf("-");
            for(int j = 1; j <= n ; j++){
                printf("*");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                printf("*");
            }
            printf("-");
            for(int j = 1; j <= n; j++){
                if(j == 1 || j == n || j == i)
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
Test Cases :
Input : 

2
5
7

Output :

*/
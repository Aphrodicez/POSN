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

    int q, n;

    scanf("%d", &q);

    while(q--){

        scanf("%d", &n);

        for(int i = 1; i <= n + 2; i++){
            for(int j = 1; j <= n - i + 2; j++){
                printf(".");
            }
            for(int j = 1; j <= i; j++){
                printf("#");
            }
            for(int j = 1; j <= n + 2; j++){
                if(j == 1 || j == n + 2 || i == 1 || i == n + 2)
                    printf("+");
                else
                    printf("#");
            }
            printf("\n");
        }

        for(int i = 1; i <= n + 2; i++){
            for(int j = 1; j <= n + 2; j++){
                if(j == 1 || j== n + 2 || i == 1 || i == n + 2)
                    printf("#");
                else
                    printf("+");
            }
            for(int j = 1; j <= n - i + 3; j++){
                printf("+");
            }
            for(int j = 1; j <= i - 1; j++){
                printf(".");
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
1
2

Output :

     
..#+++
.##+#+
###+++
###+++
#+#++.
###+..

...#++++
..##+##+
.###+##+
####++++
####++++
#++#+++.
#++#++..
####+...

*/
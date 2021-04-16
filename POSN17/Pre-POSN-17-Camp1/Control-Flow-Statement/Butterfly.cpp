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
    
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        for(int j = 0; j < 2*n - 3 - (2 * i); j++){
            printf("-");
        }
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(int j = 0; j < 2 * n - 1; j++)
        printf("*");
    printf("\n");

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf("*");
        }
        for(int j = 0; j < 1 + (2 * i); j++){
            printf("-");
        }
        for(int j = 0; j < n - i - 1; j++){
            printf("*");
        }
        cout << "\n";
    }

    return 0;
}
/*
Test Cases :
Input : 

3

Output :

*---*
**-**
*****
**-**
*---*

*/
/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Loop
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, i, j;

    scanf("%d", &n);    

    for(i = 1; i <= n; i++){
        printf("%d ", i);
    }
    printf("\n");
    
    i = n;
    while(i > 0){
        printf("%d ", i);
        i--;
    }
    printf("\n");

    i = 2;
    do{
        if(n < 2)
            break;
        printf("%d ", i);
        i += 2;
    }while(i <= n);
    printf("\n");

    for(i = n - (n % 2); i >= 2; i-=2){
        printf("%d ", i);
    }
    printf("\n");

    i = 1;
    while(i <= n){
        printf("%d ", i);
        i += 2;
    }
    printf("\n");

    i = n - (1 - (n%2));
    do{
        printf("%d ", i);
        i -= 2;
    }while(i >= 1);

    return 0;
}
/*
Test Cases :
Input : 

15

Output :

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
2 4 6 8 10 12 14
14 12 10 8 6 4 2
1 3 5 7 9 11 13 15
15 13 11 9 7 5 3 1

*/
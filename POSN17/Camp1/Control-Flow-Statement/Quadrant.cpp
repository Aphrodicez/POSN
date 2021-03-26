/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: If-Else, Modulo
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;

    scanf("%d", &n);

    n %= 360;
    n = (n + 360) % 360; // negative

    if(n % 90 == 0){
        if(n % 180 == 0)
            printf("x-axis");
        else
            printf("y-axis");
    }
    else{
        printf("%d", (n/90) + 1);
    }

    return 0;
}
/*
Test Cases :
Input : 

315
180

Output :

4
x-axis
*/
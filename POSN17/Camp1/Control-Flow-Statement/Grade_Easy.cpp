/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: If-Else
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;

    scanf("%d", &n);

    if(n >= 80)
        printf("A");
    else if(n >= 75)
        printf("B+");
    else if(n >= 70)
        printf("B");
    else if(n >= 65)
        printf("C+");
    else if(n >= 60)
        printf("C");
    else if(n >= 55)
        printf("D+");
    else if(n >= 50)
        printf("D");
    else
        printf("F");

    return 0;
}
/*
Test Cases :
Input : 

79
49

Output :

B+
F

*/
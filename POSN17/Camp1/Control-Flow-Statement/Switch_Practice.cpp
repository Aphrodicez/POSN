/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Switch Case
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;

    scanf("%d", &n);
    
    switch(n){
        case 1 : printf("Sunday"); break; 
        case 2 : printf("Monday"); break; 
        case 3 : printf("Tuesday"); break; 
        case 4 : printf("Wednesday"); break; 
        case 5 : printf("Thursday"); break; 
        case 6 : printf("Friday"); break; 
        case 7 : printf("Saturday"); break; 
        default : printf("Not a day");
    }
    return 0;
}
/*
Test Cases :
Input : 

1
7

Output :

Sunday
Saturday

*/
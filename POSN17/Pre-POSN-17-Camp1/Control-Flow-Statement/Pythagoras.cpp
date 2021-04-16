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

    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    if(c == 0){
        printf("%.2lf", sqrt((a * a) + (b * b)));
    }
    else{
        b = max(a, b);
        printf("%.2lf", sqrt((c * c) - (b * b)));
    }

    return 0;
}

/*
Test Cases :
Input : 

3.00 4.00 0.00
3.00 0.00 5.00

Output :

5.00
4.00

*/
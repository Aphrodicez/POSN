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

        for(int i = 1; i <= 1 + (2 * n); i++){
            for(int j = 1; j <= 1 + (2 * n); j++){
                if(i == 1 || j == 1){
                    printf("*");
                }
                else if(i % 2 == 1){
                    if(j <= i){
                        printf("*");
                    }
                    else if(j % 2 == 1){
                        printf("*");
                    }
                    else{
                        printf("-");
                    }
                }
                else if(i <= j){
                    if(j % 2 == 1)
                        printf("*");
                    else
                        printf("-");
                }
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

***********
*-*-*-*-*-*
***-*-*-*-*
*---*-*-*-*
*****-*-*-*
*-----*-*-*
*******-*-*
*-------*-*
*********-*
*---------*
***********

***************
*-*-*-*-*-*-*-*
***-*-*-*-*-*-*
*---*-*-*-*-*-*
*****-*-*-*-*-*
*-----*-*-*-*-*
*******-*-*-*-*
*-------*-*-*-*
*********-*-*-*
*---------*-*-*
***********-*-*
*-----------*-*
*************-*
*-------------*
***************

*/
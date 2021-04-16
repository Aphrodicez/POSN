/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Fenwick Tree
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

char a[(1 << 11) + 10][(1 << 10) + 1];

void draw(int type){
    while(type <= (1 << 11) - 1){
        int nowj = 1;
        for(int i = type; i <= (1 << 11) - 1 ; i += type * 2){
            for(int j = nowj, cnt = 1; cnt <=  type; j++, nowj++, cnt++){
                a[i][j] = '*';
            }
        }
        type *= 2;
    }
}

int main(){

    int n;

    scanf("%d", &n);

    memset(a, '-', sizeof a);

    draw(1);

    for(int i = 1; i <= (1 << n) - 1; i++){
        for(int j = 1; j <= (1 << (n-1)); j++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
Test Cases :
Input : 

1

Output :

*

*/
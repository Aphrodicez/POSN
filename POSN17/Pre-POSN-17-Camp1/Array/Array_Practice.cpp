/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Array
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main(){

    int n, k, cnt = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for(int i = n - 1; i >= 0; i--){
        printf("%d ", a[i]);
        if(a[i] == k)
            cnt++;
    }
    printf("\n%d", cnt);

    return 0;
}

/*
Test Cases :
Input : 

8
16 -20 0 14 7 -2 16 5
16

5
1 2 3 4 5
6

7
2 3 2 3 -1 3 2
3

Output :

5 16 -2 7 14 0 -20 16 
2

5 4 3 2 1 
0

2 3 -1 3 2 3 2 
3

*/
/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Math
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int q = 20, n, m, centre;

    while(q--){
        
        scanf("%d %d", &n, &m);

        centre = n - (2 * m);
        centre /= 2;

        if(centre < 0 || (4 * centre) > n){
            printf("0\n");
            continue;
        }
        n -= (4 * centre);
        n /= 2;
        printf("%d\n", n+1);
    }

    return 0;
}
/*

/*
Test Cases :
Input : 

40 15
30 12
60 40
50 18
66 26
36 11
36 16
36 18
56 20
56 22
44 18
32 14
42 20
36 16
38 14
38 16
34 20
36 16
44 14
34 14

Output :

11
10
0
12
20
5
15
19
13
15
13
20
15
10
14
0
7
12

*/
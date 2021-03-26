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
    
    int q, g, k, cnt, ans;

    scanf("%d", &q);

    while(q--){
        cnt = 1, ans = 0;

        scanf("%d %d", &g, &k);

        while(1){
            if(g - (100 * cnt) > 0){
                /// unfinished
                ans++;
                g -= 10;
                cnt--;
                cnt += k;
            }
            else
                break;
        }
        printf("%d\n", ans);
    }

    return 0;
}
/*
Test Cases :
Input : 

4
60 10
150 1
430 2
320 2

Output :

0
5
3
2

*/
/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

bool dp[110];

int sz[] = {6, 9, 20};

int main() {
    int n;
    scanf("%d", &n);
    if(n < 6) {
        printf("no\n");
        return 0;
    }
    dp[0] = 1;
    for(int i = 6; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            if(i - sz[j] >= 0 && dp[i - sz[j]]) {
                dp[i] = true;
                break;
            }
        }
        if(dp[i])
            printf("%d\n", i);
    }
    return 0;
}

/*
4

15
*/
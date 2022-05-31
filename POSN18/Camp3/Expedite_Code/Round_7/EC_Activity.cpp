/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming + Permutation
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 15e4 + 10;

int a[3][MaxN];
int dp[3][MaxN];

int main() {
    int n;
    scanf("%d", &n); 
    for(int k = 0; k < 3; k++) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[k][i]);
        }
    }
    int ans = 1e9;
    int who[] = {0, 1, 2};
    do {
        for(int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i - 1] + a[who[0]][i];
        }
        for(int state = 1; state <= 2; state++) {
            dp[state][state + 1] = dp[state - 1][state] + a[who[state]][state + 1];
            for(int i = state + 2; i <= n; i++)
                dp[state][i] = min(dp[state - 1][i - 1], dp[state][i - 1]) + a[who[state]][i];
        }
        ans = min(ans, dp[2][n]);
    } while(next_permutation(who, who + 3));
    printf("%d\n", ans);
    return 0;
}

/*
7
3 3 4 1 3 4 4
4 2 5 1 5 5 4
5 5 1 3 4 4 4
*/
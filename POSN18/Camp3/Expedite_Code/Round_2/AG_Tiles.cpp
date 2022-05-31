/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming [ Ad-Hoc ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e3 + 10;
const int MOD = 1e9 + 7;

int dp[2][MaxN];
char a[2][MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        dp[0][0] = dp[1][0] = 1;
        int n;
        scanf("%d", &n);
        for(int i = 0; i < 2; i++) {
            scanf(" %s", a[i] + 1);
        }
        for(int j = 1; j <= n; j++) {
            for(int i = 0; i < 2; i++) {
                dp[i][j] = 0;
                dp[i][j] = (dp[i][j] + dp[i][j - 1] * (a[i][j] != '#' && a[i][j - 1] != '#')) % MOD;
                dp[i][j] = (dp[i][j] + dp[i ^ 1][j - 1] * (a[i][j] != '#' && a[i ^ 1][j] != '#' && a[i ^ 1][j - 1] != '#')) % MOD;
            }
        }
        printf("%d\n", (dp[0][n] + dp[1][n]) % MOD);
    }
    return 0;
}

/*
2
2
..
..
2
.#
..
*/
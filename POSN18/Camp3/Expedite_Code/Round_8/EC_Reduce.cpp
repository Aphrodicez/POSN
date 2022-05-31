/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming + Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int a[2];

int dp[2][2];

void solve() {
    memset(a, 0, sizeof (a));
    memset(dp, 0, sizeof (dp));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i & 1]);
        if(i == 1)
            continue;
        dp[0][i & 1] = max(dp[0][i & 1 ^ 1], dp[1][i & 1 ^ 1] + a[i & 1 ^ 1] - 1);
        dp[1][i & 1] = max(dp[0][i & 1 ^ 1] + a[i & 1] - 1, dp[1][i & 1 ^ 1] + abs(a[i & 1 ^ 1] - a[i & 1]));
    }
    printf("%d\n", max(dp[0][n & 1], dp[1][n & 1]));
}

int main() {
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/*
1
5
10 5 10 5 10
*/
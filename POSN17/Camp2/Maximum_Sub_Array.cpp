/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Kadane's Algorithm 2D
    Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 5e2 + 10;
const int M = 2e5 + 10;

int dp[N][N];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &dp[i][j]);
            dp[i][j] += dp[i - 1][j];
        }
    }
    int ans = dp[1][1];
    for(int k = 1; k <= n; k++){
        for(int i = 1; i + k - 1 <= n; i++){
            int sum = 0;
            for(int j = 1; j <= n; j++){
                sum += dp[i + k - 1][j] - dp[i - 1][j];
                if(sum < 0)
                    sum = dp[i + k - 1][j] - dp[i - 1][j];
                ans = max(ans, sum);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4
0 -2 7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/
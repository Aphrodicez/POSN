/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Longest Increasing Subsequence
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void setIO();

const int N = 5e3 + 10;
const int M = 5e3 + 10;

i64 dp[2][M], a[N], b[M];

void solve() {
    memset(dp, 0, sizeof dp);
    i64 n, m;
    scanf("%lld %lld", &n, &m);
    for(i64 i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(i64 j = 1; j <= m; j++)
        scanf("%lld", &b[j]);
    for(i64 i = 1; i <= n; i++){
        for(i64 j = 1; j <= m; j++){
            dp[i % 2][j] = max({dp[(i + 1) % 2][j - 1] + abs(a[i] - b[j]), dp[(i + 1) % 2][j], dp[i % 2][j - 1]});
        }
    }
    printf("%lld", dp[n % 2][m]);
}

int main() {
    i64 q;
    scanf("%lld", &q);
    while(q--){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
1
4 4
1 2 3 4
1 2 3 4
*/
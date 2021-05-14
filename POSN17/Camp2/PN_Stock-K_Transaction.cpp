/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int N = 1e6 + 10;
const int M = 2e5 + 10;
const int T = 2;

i64 dp[T][N];

i64 price[N];

void solve() {
    i64 n, mxDiff;
    memset(dp, 0, sizeof dp);
    scanf("%lld", &n);
    for(i64 j = 1; j <= n; j++){
        scanf("%lld", &price[j]);
    }
    for(int i = 1; i <= 2; i++){
        mxDiff = -price[1];
        for(i64 j = 2; j <= n; j++){
            dp[i][j] = max(dp[i][j - 1], price[j] + mxDiff);
            mxDiff = max(mxDiff, dp[i - 1][j] - price[j]);
        }
    }
    printf("%lld\n", dp[2][n]);
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
10
2 5 2 5 7 7 34 12 5 21
*/
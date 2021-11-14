/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Quicksum 2D ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 5e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int dp[MaxN][MaxN];

void solve() {
    memset(dp, 0, sizeof dp);
    int r, c;
    cin >> r >> c;
    int n;
    cin >> n;
    for(int it = 1; it <= n; it++) {
        int i, j;
        cin >> i >> j;
        i++, j++;
        dp[i][j] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(!dp[i][j])
                ans = max(ans, 1);
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            int mxsz = min(i, j);
            for(int sz = mxsz; sz >= max(ans, 2); sz--) {
                int small_square = dp[i - 1][j - 1] - dp[i - sz + 1][j - 1] - dp[i - 1][j - sz + 1] + dp[i - sz + 1][j - sz + 1];
                int big_square = dp[i][j] - dp[i - sz][j] - dp[i][j - sz] + dp[i - sz][j - sz];
                if(sz == 2)
                    small_square = 0;
                if(big_square - small_square == 0)
                    ans = max(ans, sz);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 2;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
5 8
6
0 7 
1 3
2 0
3 6
4 2
4 5
5 5
8
0 0
0 4
4 0
4 4
0 1
2 0
2 4
4 3
*/
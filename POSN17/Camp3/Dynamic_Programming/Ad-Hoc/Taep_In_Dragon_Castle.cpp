/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc]
    Status	: Accepted
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
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int N = 2e1 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dp[N][N], tmp[N][N];

void solve() {
    int r, c, t, p;
    cin >> r >> c >> t >> p;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dp[i][j] = tmp[i][j] = 1;
        }
    }
    while(--t) {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++){
                for(int k = 0; k < 4; k++) {
                    int ii = i + d4i[k];
                    int jj = j + d4j[k];
                    if(ii < 1 || jj < 1 || ii > r || jj > c)
                        continue;
                    dp[i][j] += tmp[ii][jj];
                    dp[i][j] %= p;
                }
            }
        }
        memcpy(tmp, dp, sizeof dp);
    }
    int ans = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            ans += dp[i][j];
            ans %= p;
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
2 2 3 10
2 2 3 100
*/
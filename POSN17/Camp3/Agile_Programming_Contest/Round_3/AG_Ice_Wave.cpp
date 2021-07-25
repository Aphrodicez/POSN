/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Knapsack]
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

const int N = 2e4;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

void TESTCASE() {
    
}

i64 dp[2][2 * N + 10];

void solve() {
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    i64 ans = 0;
    int num;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        for(int j = 0; j < 2 * N + 10; j++)
            dp[i & 1][j] = 0;
        dp[(i & 1) ^ 1][0 + N]++;
        dp[(i & 1) ^ 1][0 + N] %= MOD;
        for(int j = -N; j <= N; j++) {
            int l = j - num, r = j + num; 
            if(l >= -2e4) {
                dp[i & 1][l + N] += dp[(i & 1) ^ 1][j + N];
                dp[i & 1][l + N] %= MOD;
            }
            if(r <= 2e4) {
                dp[i & 1][r + N] += dp[(i & 1) ^ 1][j + N];
                dp[i & 1][r + N] %= MOD;
            }
        }
        ans += dp[i & 1][0 + N];
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q;
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
1
4
4 4 2 2
*/
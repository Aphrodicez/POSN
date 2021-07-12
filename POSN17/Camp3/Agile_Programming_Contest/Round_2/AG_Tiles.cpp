/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
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

const int N = 5e3 + 10;
const int M = 2e5 + 10;

const i64 MOD = 1e9 + 7;

i64 dp[4][N];

char a[4][N];

void TESTCASE() {

}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 0;
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= 2; i++) {
        dp[i][n + 1] = 0;
        a[i][n + 1] = '.';
        if(a[i][1] == '.')
            dp[i][1] = 1;
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= 2; i++) {
            if(a[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }
            if(a[i][j + 1] != '#') {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
            if(a[i - 1][j] != '#' && a[i - 1][j + 1] != '#') {
                dp[i - 1][j + 1] += dp[i][j];
                dp[i - 1][j + 1] %= MOD;
            }
            if(a[i + 1][j] != '#' && a[i + 1][j + 1] != '#') {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= MOD;
            }
        }
    }
    i64 ans = 0;
    for(int i = 1; i <= 2; i++) {
        if(a[i][n + 1] == '#')
            continue;
        ans += dp[i][n + 1];
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
2
2
..
..
2
.#
..
*/
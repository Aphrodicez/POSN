/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Divide and Conquer
    Status	: Accepted
    Created	: 21 August 2021 [01:59]
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dp[(1 << 9) + 10][(1 << 9) + 10];

int ans = 0;

const int di[] = {1, 0, 0, 1};
const int dj[] = {0, 0, 1, 1};

void divide(int uli, int ulj, int dri, int drj, int n) {
    int sum = dp[dri][drj] - dp[dri][ulj - 1] - dp[uli - 1][drj] + dp[uli - 1][ulj - 1];
    if(!(sum % (n * n))) {
        ans += 2;
        return ;
    }
    ans += 1;
    int midi = uli + n / 2 - 1, midj = ulj + n / 2 - 1;
    for(int k = 0; k < 4; k++)
        divide(uli + (n / 2 * di[k]), ulj + (n / 2 * dj[k]), dri - (n / 2 *(1 - di[k])), drj - (n / 2 * (1 - dj[k])), n / 2);
}

void solve() {
    ans = 0;
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> dp[i][j];
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    divide(1, 1, n, n, n);
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
4
1 1 1 1
1 1 0 1
0 1 0 0
0 0 1 1
8
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
*/
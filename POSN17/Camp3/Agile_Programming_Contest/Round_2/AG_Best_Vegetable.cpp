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

const int N = 7e1;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dp[N + 10][N * N + 10];

void solve() {
    memset(dp, 0, sizeof dp);
    int n, K, L;
    cin >> n >> K >> L;
    L = min(L, n * n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for(int swapCnt = min(i, K); swapCnt >= 1; swapCnt--) {
            for(int w = i - swapCnt; w <= L; w++) {
                dp[swapCnt][w] = max(dp[swapCnt][w], dp[swapCnt - 1][w - (i - swapCnt)] + num);
            }
        }
    }
    for(int i = 0; i <= L; i++) {
        ans = max(ans, dp[K][i]);
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
5 2 3
60 54 32 95 93
*/
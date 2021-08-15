/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Kadane's Algorithm
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

const int N = 5e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dp[N][N];

void solve() {
    int n;
    cin >> n;
    int ans;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> dp[i][j];
            dp[i][j] += dp[i - 1][j];
        }
    }
    ans = dp[1][1];
    for(int sz = 1; sz <= n; sz++) {
        for(int i = sz; i <= n; i++) {
            int sum = 0;
            for(int j = 1; j <= n; j++) {
                sum += dp[i][j] - dp[i - sz][j];
                ans = max(ans, sum);
                sum = max(sum, 0);
            }
        }
    }
    cout << ans << "\n";
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
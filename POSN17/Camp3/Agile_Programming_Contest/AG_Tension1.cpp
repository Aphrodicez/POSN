/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming + Quicksum
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

const int N = 1e6 + 10;
const int M = 2e5 + 10;

i64 n, k;

i64 dp[N], qs[N];

void TESTCASE() {
    i64 m, ans = 0;
    cin >> m;
    for(i64 i = 1; i <= k; i++)
        dp[i] = qs[i];
    for(i64 i = k + 1; i <= n; i++) {
        dp[i] = min(dp[i - k] + (qs[i] - qs[i - k]) / 2 + m, dp[i - 1] + qs[i] - qs[i - 1]);
    }
    cout << dp[n] << "\n";
}

void solve() {
    cin >> n >> k;
    for(i64 i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] += qs[i - 1];
    }
    i64 q;
    cin >> q;
    while(q--) {
        TESTCASE();
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
7 2
10 8 2 4 16 6 12
2
5 
100
*/
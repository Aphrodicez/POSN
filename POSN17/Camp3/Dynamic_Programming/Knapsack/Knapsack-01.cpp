/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Knapsack
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

const int N = 1e2 + 10;
const int M = 1e4 + 10;

int dp[M];

void TESTCASE() {
    
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int val, w;
        cin >> val >> w;
        for(int j = m; j - w >= 0; j--) {
            dp[j] = max(dp[j], dp[j - w] + val);
        }
    }
    cout << dp[m] << "\n";
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
4 8
15 1
10 5
9 3
5 4
*/
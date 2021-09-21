/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

const int MaxN = 4e2;
const int MaxH = 4e2;
const int MOD = 1e9 + 7;

long long dp[MaxN + 10][MaxH + 10];
long long qs[MaxN + 10][MaxH + 10];

void TESTCASE() {
    
}

void solve() {
    qs[0][0] = dp[0][0] = 1;
    for(int i = 1; i <= MaxH; i++) {
        qs[0][i] = qs[0][i - 1] + dp[0][i]; 
    }
    for(int n = 1; n <= MaxN; n++) {
        for(int h = 1; h <= n; h++) {
            for(int root = 1; root <= n; root++) {
                /// Left Subtree Height is h - 1
                dp[n][h] = (dp[n][h] + (dp[root - 1][h - 1] * qs[n - root][min(n - root, h - 1)]) % MOD) % MOD;
                /// Left Subtree Height is 0 -> h - 2
                if(h - 2 >= 0)
                    dp[n][h] = (dp[n][h] + (qs[root - 1][min(root - 1, h - 2)] * dp[n - root][h - 1]) % MOD) % MOD;
            }
            qs[n][h] = (qs[n][h - 1] + dp[n][h]) % MOD;
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int n, h;
        cin >> n >> h;
        cout << (((qs[n][n] - qs[n][min(n, h - 1)]) % MOD) + MOD) % MOD << "\n";
    }
}

int main() {
    setIO();
    int q = 1;
    
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
3
3 1
3 2
3 3
*/
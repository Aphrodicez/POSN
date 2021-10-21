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

const int D = 2e2 + 10;
const int M = 4e1 + 10;
const int R = 1e2 + 10;

void TESTCASE() {
    
}

int dayA[M], dayB[M], useA[M], useB[M];

int dp[D][R][R];

void solve() {
    memset(dp, 0, sizeof dp);
    int d, m, r;
    cin >> d >> m >> r;
    int ka, kb;
    cin >> ka >> kb;
    for(int i = 0; i < m; i++)
        cin >> dayA[i];
    for(int i = 0; i < m; i++)
        cin >> dayB[i];
    for(int i = 0; i < m; i++)
        cin >> useA[i];
    for(int i = 0; i < m; i++)
        cin >> useB[i];
    int ans = 0;
    for(int now = 0; now < m; now++) {
        if(useA[now] != -1) {
            for(int i = d; i - dayA[now] >= 0; i--) {
                for(int j = min(ka, r); j - useA[now] >= 0; j--) {
                    for(int k = min(kb, r - j); k >= 0; k--) {
                        if(dp[i - dayA[now]][j - useA[now]][k] == now) {
                            dp[i][j][k] = dp[i - dayA[now]][j - useA[now]][k] + 1;
                            if(dp[i][j][k] == m) {
                                ans = max(ans, r - (j + k));
                            }
                        }
                    }
                }
            }
        }
        if(useB[now] != -1) {
            for(int i = d; i - dayB[now] >= 0; i--) {
                for(int j = min(kb, r); j - useB[now] >= 0; j--) {
                    for(int k = min(ka, r - j); k >= 0; k--) {
                        if(dp[i - dayB[now]][k][j - useB[now]] == now) {
                            dp[i][k][j] = dp[i - dayB[now]][k][j - useB[now]] + 1;
                            if(dp[i][k][j] == m) {
                                ans = max(ans, r - (j + k));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << (ans > 0 ? ans : -1) << "\n";
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
200 4 10
5 4
5 8 -1 10
100 200 100 50
1 2 -1 3
1 3 2 2
200 4 50
10 10
5 8 -1 10
100 200 200 50
1 2 -1 3
1 3 2 2
*/
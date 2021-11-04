/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Minimum Path ]
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
    long long u, d, l, r; 
};

const int MaxN = 2e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <vector <GRAPH>> g;
vector <vector <long long>> downright, upleft;
vector <vector <long long>> dp;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    g.assign(n + 10, vector<GRAPH>(m + 10, {(long long)1e18, (long long)1e18, (long long)1e18, (long long)1e18}));
    downright.assign(n + 10, vector <long long>(m + 10, 1e18));
    upleft.assign(n + 10, vector <long long>(m + 10, 1e18));
    dp.assign(n + 10, vector <long long>(m + 10, 1e18));
    
    long long w;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m - 1; j++) {
            cin >> w;
            g[i][j].r = w;
            g[i][j + 1].l = w;
        }
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> w;
            g[i][j].d = w;
            g[i + 1][j].u = w;
        }
    }
    downright[1][1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 && j == 1)
                continue;
            downright[i][j] = min(downright[i - 1][j] + g[i - 1][j].d, downright[i][j - 1] + g[i][j - 1].r);
        }
    }
    upleft[n][m] = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            if(i == n && j == m)
                continue;
            upleft[i][j] = min(upleft[i + 1][j] + g[i + 1][j].u, upleft[i][j + 1] + g[i][j + 1].l);
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i + 1][j], upleft[i][j] + downright[i][j]);
        }
    }
    while(q--) {
        int r, c;
        cin >> r >> c;
        r++, c++;
        if(c == 1 || r + 1 > n) {
            cout << -1 << "\n";
            continue;
        }
        cout << dp[r + 1][c - 1] << "\n";
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
3 5 2
1 1 7 8
1 1 3 6
9 4 1 1
4 3 1 2 4
6 2 2 3 8
0 4
1 2
*/
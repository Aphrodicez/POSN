/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
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

const int N = 1e4 + 10;
const int M = 2e5 + 10;

int cost[N];
int dp[3][N];

vector <int> g[N];

void TESTCASE() {
    
}

void dfs(int u, int p) {
    if(dp[2][u] != 1e9)
        return ;
    dp[1][u] = cost[u] + 0;
    int sum2 = 0;
    for(int x : g[u]) {
        if(x == p)
            continue;
        dfs(x, u);
        sum2 += dp[2][x];
        dp[1][u] += min(dp[0][x], dp[2][x]);
    }
    dp[0][u] = sum2;
    dp[2][u] = dp[1][u];
    for(int x : g[u]) {
        if(x == p)
            continue;
        dp[2][u] = min(dp[2][u], sum2 - dp[2][x] + dp[1][x]);
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < 3; k++)
            dp[k][i] = 1e9;
        cin >> cost[i];
    }
    int u, v;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    cout << dp[2][1] << "\n";
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
6
4
9
1
20
5
3
2 1
3 2
2 4
5 4
4 6
*/
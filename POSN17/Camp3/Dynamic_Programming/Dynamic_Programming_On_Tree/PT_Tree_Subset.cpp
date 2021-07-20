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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[N];

i64 tree[N];
i64 dp[2][N];

void dfs(int u, int p) {
    if(dp[0][u] != -1)
        return ;
    dp[0][u] = 0;
    dp[1][u] = tree[u];
    for(int x : g[u]) {
        if(x == p)
            continue;
        dfs(x, u);
        dp[0][u] += max(dp[1][x], dp[0][x]);
        dp[1][u] += dp[0][x];
    }
}

void solve() {
    memset(dp, -1, sizeof (dp));
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        cin >> tree[i];
    }
    int u, v;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    cout << max(dp[1][1], dp[0][1]) << "\n";
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
3
3 4 3
1 2
2 3
5
3 2 10 10 10
1 2
2 3
1 5
4 2
*/
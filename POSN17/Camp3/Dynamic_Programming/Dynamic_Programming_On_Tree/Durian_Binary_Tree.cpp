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
    int u;
    i64 w;
};

const int N = 1e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <GRAPH> g[N];

i64 dp[N][N];

i64 dfs(int u, int p, i64 w, int k) {
    if(!k)
        return 0;
    if(dp[k][u] != -1)
        return dp[k][u];
    int nextk = k - 1;
    vector <GRAPH> children;
    for(auto x : g[u]) {
        if(x.u == p)
            continue;
        children.push_back({x.u, x.w});
    }
    if(!children.size())
        return dp[k][u] = w + 0;
    if(children.size() == 1) {
        return dp[k][u] = w + dfs(children[0].u, u, children[0].w, nextk);
    }
    if(children.size() == 2) {
        i64 sum = 0;
        for(int l = 0; l <= nextk; l++) {
            int r = nextk - l; 
            sum = max(sum, dfs(children[0].u, u, children[0].w, l) + dfs(children[1].u, u, children[1].w, r));
        }
        return dp[k][u] = w + sum;
    }
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n, k;
    cin >> n >> k;
    int u, v;
    i64 w;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cout << dfs(1, 1, 0, k + 1) << "\n";
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
5 2
1 3 1
1 4 10
2 3 20
3 5 20
*/
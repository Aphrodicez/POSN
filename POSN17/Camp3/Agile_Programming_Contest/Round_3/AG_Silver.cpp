/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree + Disjoint Set Union
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

const int N = 3e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[N];

bool visited[N];

int diameter[N], p[N];

int dp[2][N];

int ans = 0;

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

void merge(int u, int v) {
    int ru = find_root(u);
    int rv = find_root(v);
    if(ru == rv)
        return;
    p[ru] = rv;
}

void dfs(int u, int pa) {
    visited[u] = true;
    for(auto x : g[u]) {
        if(x == pa)
            continue;
        dfs(x, u);
        merge(x, u);
        if(dp[0][x] + 1 > dp[0][u]) {
            swap(dp[0][u], dp[1][u]);
            dp[0][u] = dp[0][x] + 1;
        }
        else if(dp[0][x] + 1 > dp[1][u]) {
            dp[1][u] = dp[0][x] + 1;
        }
    }
    ans = max(ans, dp[0][u] + dp[1][u]);
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        p[i] = i;
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ans = 0;
            dfs(i, i);
            diameter[i] = ans;
        }
    }
    int opr;
    while(q--) {
        cin >> opr;
        if(opr == 1) {
            cin >> u;
            cout << diameter[find_root(u)] << "\n";
        }
        if(opr == 2) {
            cin >> u >> v;
            int ru = find_root(u);
            int rv = find_root(v);
            if(ru == rv)
                continue;
            /// ceil
            diameter[ru] = max({( (diameter[ru] + 1) / 2) + ( (diameter[rv] + 1) / 2) + 1, diameter[ru], diameter[rv]});
            merge(rv, ru);
        }
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
10 0 9
2 1 2
2 4 3
2 3 5
1 3
2 5 1
2 6 8
2 8 7
2 7 9
1 7
*/
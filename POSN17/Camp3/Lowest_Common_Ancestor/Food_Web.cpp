/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Lowest Common Ancestor [ Binary Lifting ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

vector <int> g[MaxN];
int degin[MaxN];
int level[MaxN];
int dp[20 + 1][MaxN];

void dfs(int u, int p) {
    level[u] = level[p] + 1;
    dp[0][u] = p;
    for(auto x : g[u]) {
        if(x == p)
            continue;
        dfs(x, u);
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v);
        degin[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!degin[i]) {
            dfs(i, i);
        }
    }
    for(int k = 1; k <= 20; k++) {
        for(int i = 1; i <= n; i++) {
            dp[k][i] = dp[k - 1][dp[k - 1][i]];
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if(level[u] > level[v])
            swap(v, u);
        for(int i = 20; i >= 0; i--) {
            if(level[dp[i][v]] < level[u])
                continue;
            v = dp[i][v];
        }
        if(u == v) {
            printf("%d\n", u);
            continue;
        }
        for(int i = 20; i >= 0; i--) {
            if(dp[i][u] != dp[i][v]) {
                u = dp[i][u];
                v = dp[i][v];
            }
        }
        printf("%d\n", dp[0][u]);
    }
}

int main() {
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
13
1 2
1 3
2 9
2 6
2 8
6 10
6 5
3 7
7 11
7 13
13 4
13 12
5
10 5
11 12
9 7
10 8
9 8
*/
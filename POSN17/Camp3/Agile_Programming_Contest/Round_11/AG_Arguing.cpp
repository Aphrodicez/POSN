/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union + Graph Theory + Math
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

vector <int> adj[MaxN];

int p[MaxN];

int find_root (int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

int cntv[MaxN], cnte[MaxN];

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    iota(p + 1, p + 1 + n, 1);
    int u, v;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        int ru = find_root(u);
        int rv = find_root(v);
        p[ru] = rv;
    }
    for(int i = 1; i <= n; i++) {
        int ri = find_root(i);
        cntv[ri]++;
        cnte[ri] += adj[i].size();
    }
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        if(!cntv[i])
            continue;
        cnte[i] /= 2;
        if(cnte[i] > cntv[i]) {
            ans = 0;
            printf("%lld\n", ans);
            return ;
        }
        if(cnte[i] == cntv[i]) {
            ans *= 2;
            ans %= MOD;
            continue;
        }
        if(cnte[i] == cntv[i] - 1) {
            ans *= cntv[i];
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);
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
5 4
1 2
3 2
4 5
4 5
*/
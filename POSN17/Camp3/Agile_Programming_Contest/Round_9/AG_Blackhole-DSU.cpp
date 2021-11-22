/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union
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
int level[MaxN], parent[MaxN];
bool isBlackhole[MaxN];

int find_root(int u) {
    if(parent[u] == u)
        return u;
    return parent[u] = find_root(parent[u]);
}

void dfs(int u, int p, int lvl = 1) {
    level[u] = lvl;
    for(int x : g[u]) {
        if(level[x] && level[x] < level[u])
            continue;
        dfs(x, u, level[u] + 1);
    }
}
void update(int u, int root) {
    isBlackhole[u] = true;
    parent[u] = root;
    for(int x : g[u]) {
        if(level[x] < level[u])
            continue;
        if(parent[x] != x)
            continue;
        update(x, root);
    }
}

void solve() {
    int n, q;
    scanf("%d %d", &n, &q);
    iota(parent + 1, parent + 1 + n, 1);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 1);

    while(q--) {
        int opr, u;
        scanf("%d %d", &opr, &u);
        if(!opr) {
            if(find_root(u) == u)
                update(u, u);
        }
        else if(opr) {
            int ru = find_root(u);
            if(isBlackhole[ru])
                printf("%d\n", ru);
            else
                printf("-1\n");
        }
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
9 6
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8
1 3
0 8
1 6
1 7
0 2
1 9
*/
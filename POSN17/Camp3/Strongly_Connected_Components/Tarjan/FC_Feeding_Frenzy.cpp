/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Tarjan's Strongly Connected Component + Kahn's Algorithm
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

const int MaxN = 5e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

vector <int> adj[MaxN];

int idx[MaxN], low[MaxN];
stack <int> st;
bitset <MaxN> onstack;
int comp[MaxN];

unordered_set <int> gt[MaxN];
int degin[MaxN], level[MaxN];
int comp_sz[MaxN], cnt_level[MaxN];
queue <int> topo;

int id = 0;
int comp_id = 0;

void dfs(int u) {
    idx[u] = low[u] = ++id;
    onstack[u] = true;
    st.push(u);
    for(int x : adj[u]) {
        if(!idx[x]) {
            dfs(x);
            low[u] = min(low[u], low[x]);
        }
        else if(onstack[x]) {
            low[u] = min(low[u], idx[x]);
        }
    }
    if(idx[u] == low[u]) {
        ++comp_id;
        while(!comp[u]) {
            comp[st.top()] = comp_id;
            onstack[st.top()] = false;
            st.pop();
        }
    }
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
    }
    for(int i = 0; i < n; i++) {
        if(!idx[i])
            dfs(i);
    }
    for(int i = 0; i < n; i++) {
        comp_sz[comp[i]]++;
        for(int x : adj[i]) {
            if(comp[i] == comp[x])
                continue;
            if(gt[comp[i]].find(comp[x]) != gt[comp[i]].end())
                continue;
            gt[comp[i]].insert(comp[x]);
            degin[comp[x]]++;
        }
    }
    for(int i = 1; i <= comp_id; i++) {
        if(!degin[i]) {
            topo.push(i);
            level[i] = 1;
        }
    }
    int k = 0;
    while(!topo.empty()) {
        int u = topo.front();
        topo.pop();
        cnt_level[level[u]] += comp_sz[u];
        k = max(k, level[u]);
        for(int x : gt[u]) {
            level[x] = max(level[x], level[u] + 1);
            if(--degin[x] == 0)
                topo.push(x);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d ", cnt_level[i]);
    }
    printf("\n");
    printf("%d\n", level[comp[0]]);
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
10 20
4 5
6 3
4 7
2 6
8 4
0 8
5 6
8 1
1 4
5 4
5 8
8 3
7 3
0 9
0 3
5 6
5 5
2 9
7 9
1 0

10 0

10 2
5 6
0 1

4 3
0 1
1 2
2 3

4 5
0 1
1 2
2 0
2 3
1 3

3 2
0 1
1 0

4 3
2 1
2 0
1 3
*/
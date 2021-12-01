/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Tarjan's Strongly Connected Component
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

int idx[MaxN], low[MaxN], comp[MaxN];
bitset <MaxN> onstack;

stack <int> st;

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
            int top = st.top();
            st.pop();
            comp[top] = comp_id;
            onstack[top] = false;
        }
    }
}

void solve() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++) {
        int di;
        scanf("%d", &di);
        for(int j = 1; j <= di; j++) {
            int v;
            scanf("%d", &v);
            adj[i].emplace_back(v);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!comp[i])
            dfs(i);
    }
    while(q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf(comp[u] == comp[v] ? "yes\n" : "no\n");
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
4 4 2
2 2 4
1 3
1 1
0
3 1
1 4
*/
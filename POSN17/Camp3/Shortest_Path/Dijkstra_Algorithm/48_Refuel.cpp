/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm Kth State
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
    int u, w, fuel;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;
const int K = 1e2 + 10;

int cost[N], dis[K][N];

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

void solve() {
    while(!dijk.empty())
        dijk.pop();
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i <= n - 1; i++) {
        cin >> cost[i];
        g[i].clear();
    }
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int st, en, capa;
    cin >> capa >> st >> en;
    for(int k = 0; k <= capa; k++) {
        for(int i = 0; i <= n - 1; i++) {
            dis[k][i] = 1e9;
        }
    }
    dis[0][st] = 0;
    dijk.push({st, 0, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int fuel = dijk.top().fuel;
        dijk.pop();
        if(u == en) {
            cout << w << "\n";
            return ;
        }
        if((fuel + 1 <= capa) && dis[fuel + 1][u] > dis[fuel][u] + cost[u]) {
            dis[fuel + 1][u] = dis[fuel][u] + cost[u];
            dijk.push({u, dis[fuel + 1][u], fuel + 1});
        }
        for(auto x: g[u]) {
            if(fuel - x.w < 0)
                continue;
            if(dis[fuel - x.w][x.u] <= dis[fuel][u])
                continue;
            dis[fuel - x.w][x.u] = dis[fuel][u];
            dijk.push({x.u, dis[fuel - x.w][x.u], fuel - x.w});
        }
    }
    cout << -99 << "\n";
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
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
20 1 4
*/
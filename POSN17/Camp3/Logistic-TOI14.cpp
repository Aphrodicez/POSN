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
    int u, w, fuel, usedTicket;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e2 + 10;
const int M = 2e5 + 10;
const int K = 1e2 + 10;

int cost[N], dis[2][K][N];

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    int st, en, capa;
    cin >> st >> en >> capa;
    int m;
    cin >> m;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int k = 0; k <= capa; k++) {
        for(int i = 1; i <= n; i++) {
            dis[0][k][i] = dis[1][k][i] = 1e9;
        }
    }
    dis[0][0][st] = 0;
    dijk.push({st, 0, 0, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int fuel = dijk.top().fuel;
        int usedTicket = dijk.top().usedTicket;
        dijk.pop();
        if((!usedTicket) && dis[usedTicket + 1][capa][u] > dis[usedTicket][fuel][u]) {
            dis[usedTicket + 1][capa][u] = dis[usedTicket][fuel][u];
            dijk.push({u, dis[usedTicket + 1][capa][u], capa, usedTicket + 1});
        }
        if((fuel + 1 <= capa) && dis[usedTicket][fuel + 1][u] > dis[usedTicket][fuel][u] + cost[u]) {
            dis[usedTicket][fuel + 1][u] = dis[usedTicket][fuel][u] + cost[u];
            dijk.push({u, dis[usedTicket][fuel + 1][u], fuel + 1, usedTicket});
        }
        for(auto x: g[u]) {
            if(fuel - x.w < 0)
                continue;
            if(dis[usedTicket][fuel - x.w][x.u] <= dis[usedTicket][fuel][u])
                continue;
            dis[usedTicket][fuel - x.w][x.u] = dis[usedTicket][fuel][u];
            dijk.push({x.u, dis[usedTicket][fuel - x.w][x.u], fuel - x.w, usedTicket});
        }
    }
    cout << min(dis[1][capa][en], dis[0][capa][en]) << "\n";
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4
7 1 8 10
1 4 100
5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20

5
10 1 3 10 30
1 4 20
4
1 2 1
1 5 5
4 5 20
3 4 2
*/
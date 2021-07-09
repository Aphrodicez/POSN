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
    int u, w, edgeUsed;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 2e3 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

int dis[N][N];

int n, st, en, m;

void TESTCASE() {
    int h;
    cin >> h;
    int ans = 1e9 + 10;
    for(int i = 0; i <= n - 1; i++) {
        ans = min(ans, dis[i][en] + i * h);
    }
    cout << ans << " ";
}

void solve() {
    cin >> n >> st >> en >> m;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for(int i = 0; i <= n - 1; i++) {
        for(int j = 0; j <= n - 1; j++) {
            dis[i][j] = 1e9 + 10;
        }
    }
    dis[0][st] = 0;
    dijk.push({st, 0, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int edgeUsed = dijk.top().edgeUsed;
        dijk.pop();
        for(auto x: g[u]) {
            int nextEdgeUsed = edgeUsed;
            if(u != st)
                nextEdgeUsed++;
            if(dis[nextEdgeUsed][x.u] <= dis[edgeUsed][u] + x.w)
                continue;
            dis[nextEdgeUsed][x.u] = dis[edgeUsed][u] + x.w;
            dijk.push({x.u, dis[nextEdgeUsed][x.u], nextEdgeUsed});
        }
    }
    int q;
    cin >> q;
    while(q--) {
        TESTCASE();
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
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm + Bitmasking
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
    int u, w, mask;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e4 + 10;
const int M = 2e5 + 10;
const int K = 8;

int dis[1<<K][N];

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

void TESTCASE() {
    int en, q, x, mask = 0;
    cin >> en >> q;
    while(q--) {
        cin >> x;
        mask |= 1 << (x - 1);
    }
    int ans = 1e9;
    for(int k = 0; k <= (1 << 8) - 1; k++) {
        if(mask & k)
            continue;
        ans = min(ans, dis[k][en]);
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
}

void solve() {
    int n, m, st, q;
    cin >> n >> m >> st >> q;
    int u, v, w, x;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w >> x;
        g[u].push_back({v, w, 1 << (x - 1)});
        g[v].push_back({u, w, 1 << (x - 1)});
    }
    for(int k = 0; k <= (1 << 8) - 1; k++) {
        for(int i = 1; i <= n; i++) {
            dis[k][i] = 1e9;
        }
    }
    dis[0][st] = 0;
    dijk.push({st, 0, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int mask = dijk.top().mask;
        dijk.pop();
        for(auto x: g[u]) {
            int nextmask = mask | x.mask;
            if(dis[nextmask][x.u] <= dis[mask][u] + x.w)
                continue;
            dis[nextmask][x.u] = dis[mask][u] + x.w;
            dijk.push({x.u, dis[nextmask][x.u], nextmask});
        }
    }
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
4 5 1 2
1 2 5 2
1 4 8 4
2 4 3 1
2 3 6 1
3 4 1 3
3 1 3
3 2 1 3
*/
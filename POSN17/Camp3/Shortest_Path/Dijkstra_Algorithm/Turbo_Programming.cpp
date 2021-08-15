/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm
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
    int u, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dis[N];

priority_queue <GRAPH> dijk;
vector <GRAPH> g[N];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        dis[i] = 1e9;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    int st, en;
    st = 1;
    dis[st] = 0;
    dijk.push({st, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        dijk.pop();
        for(auto x : g[u]) {
            if(dis[x.u] <= dis[u] + x.w)
                continue;
            dis[x.u] = dis[u] + x.w;
            dijk.push({x.u, dis[x.u]});
        }
    }
    while(q--) {
        cin >> en;
        cout << (dis[en] == 1e9 ? -1 : dis[en]) << "\n";
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
6 5 3
1 2 10
2 3 10
3 4 10
4 5 10
1 5 50
6
5
4
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra Kth State
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
    int u, w, state;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

int dis[2][N];

void solve() {
    int n, m, k, t, u, v, w;
    cin >> n >> m >> k >> t;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++) {
        dis[0][i] = dis[1][i] = (int)1e9 + 10;
    }
    dis[0][1] = 0;
    dijk.push({1, 0, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int state = dijk.top().state;
        dijk.pop();
        if(u == n) {
            if(w > t)
                cout << "No Honey TT" << '\n';
            else {
                cout << "Happy Winnie the Pooh :3" << '\n';
                cout << w << '\n';
            }
            return ;
        }
        for(auto x: g[u]) {
            int nextw = dis[state][u] + x.w;
            if(dis[state][x.u] > nextw && nextw <= t) {
                dis[state][x.u] = nextw;
                dijk.push({x.u, nextw, state});
            }
            if(state)
                continue;
            nextw = dis[state][u] + k;
            if(dis[state + 1][x.u] > nextw && nextw <= t) {
                dis[state + 1][x.u] = nextw;
                dijk.push({x.u, nextw, state + 1});
            }
        }
    }
    cout << "No Honey TT" << '\n';
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
1 2 2
2 3 3
1 3 5
1 4 4
3 4 3

7 7 2 4
1 2 1
2 3 1
3 4 1
4 7 3
2 5 1
5 6 1
4 6 1
*/
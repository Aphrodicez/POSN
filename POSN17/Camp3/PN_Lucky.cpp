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
    int u, w, luck;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 5e4 + 10;
const int M = 2e5 + 10;
const int K = 3e1 + 10;

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

vector <vector <int>> dis;

int luckArr[N];

void solve() {
    int n, m, l, st, en;
    cin >> n >> m >> l;
    cin >> st >> en;
    while(!dijk.empty())
        dijk.pop();
    for(int i = 1; i <= n; i++)
        g[i].clear();
    int u, v, w;
    for(int i = 1; i <= n; i++) {
        cin >> luckArr[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dis.assign(K, vector <int> (N, 1e9));
    dis[0][st] = 0;
    dijk.push({st, 0, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int luck = dijk.top().luck;
        dijk.pop();
        if(u == en && luck == l) {
            cout << dis[l][en] << "\n";
            return ;
        }
        for(auto x: g[u]) {
            int nextLuck = luck;
            if(luckArr[x.u] == luck + 1) 
                nextLuck = luck + 1;
            if(dis[nextLuck][x.u] <= dis[luck][u] + x.w)
                continue;
            dis[nextLuck][x.u] = dis[luck][u] + x.w;
            dijk.push({x.u, dis[nextLuck][x.u], nextLuck});
        }
    }
    cout << -1 << "\n";
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
1
6 8 3
1 6
0 2 1 1 4 3
1 2 20
1 3 80
3 2 100
2 4 30
4 2 40
2 6 25
2 5 15
5 6 50
*/
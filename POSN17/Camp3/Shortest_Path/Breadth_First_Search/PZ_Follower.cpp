/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search Kth State
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

const int N = 1e2 + 10;
const int M = 2e5 + 10;
const int K = 1e3 + 100; /// 1023

struct GRAPH {
    int u, w;
    bool operator < (const GRAPH &o) const{
        return w > o.w;
    }
};

v(GRAPH) g[N];

int mark[K][N];

queue <GRAPH> bfs;

void solve() {
    while(!bfs.empty())
        bfs.pop();
    int n, m, st, en;
    cin >> n >> m >> st >> en;
    memset(mark, 0, sizeof mark);
    for(int i = 1; i <= n; i++)
        g[i].clear();
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    mark[0][st] = 1;
    bfs.push({st, 0});
    int ans = 1023;
    while(!bfs.empty()){
        int u = bfs.front().u;
        int w = bfs.front().w;
        bfs.pop();
        if(u == en){
            ans = min(ans, w);
        }
        for(auto x: g[u]){
            int nextw = w ^ x.w;
            if(mark[nextw][x.u])
                continue;
            mark[nextw][x.u] = 1;
            bfs.push({x.u, nextw});
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--){
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
4 4 1 4
1 2 3
1 3 5
2 3 1
3 4 4
*/
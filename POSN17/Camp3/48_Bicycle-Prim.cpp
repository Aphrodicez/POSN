/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Minimum Spanning Tree [Prim] + Compress Number
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
    int u;
    i64 w;
    bool operator < (const GRAPH &o) const {
        return w < o.w;
    }
};

const int N = 5e4 + 10;
const int M = 2e5 + 10;

unordered_map <int, int> mapp;

vector <GRAPH> g[N];

priority_queue <GRAPH> pq;

bool visited[N];

void solve() {
    while(!pq.empty())
        pq.pop();
    mapp.clear();
    memset(visited, false, sizeof visited);
    int n, m;
    cin >> n >> m;
    int u, v;
    i64 w;
    i64 ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> u;
        mapp[u] = i;
        g[i].clear();
    }
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[mapp[u]].push_back({mapp[v], w});
        g[mapp[v]].push_back({mapp[u], w});
        ans += w;
    }
    u = 1;
    pq.push({u, 0});
    while(!pq.empty()) {
        int u = pq.top().u;
        i64 w = pq.top().w;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        ans -= w;
        for(auto x: g[u]) {
            if(visited[x.u])
                continue;
            pq.push({x.u, x.w});
        }
    }
    cout << ans << "\n";
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
8 10
1 2 3 4 5 6 7 8
1 2 3
1 5 5
2 3 4
2 6 3
3 4 2
3 7 5
4 8 5
5 6 2
6 7 7
7 8 3
14 18
5 11 13 0 3 8 6 2 12 14 1 9 10 4 
5 0 2
5 6 7
5 10 7
11 6 5
11 10 9
11 12 4
13 14 3
13 8 5
13 12 6
0 1 7
3 2 7
3 8 1
3 4 1
8 9 1
6 1 7
2 1 9
14 9 1
9 4 3
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm Kth State + Binary Search
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
    int u, w, state, edgeidx;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

int n, m;

priority_queue <GRAPH> dijk;

vector <GRAPH> g[N];

vector <vector <int>> dis;

int dijkstra (int st, int en, int maxEdge) {
    dis.assign(2, vector<int> (N, 1e9));
    dis[1][st] = 0;
    dijk.push({st, 0, 1, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int state = dijk.top().state;
        int nextstate = state + 1; 
        dijk.pop();
        for(auto x: g[u]) {
            if(x.edgeidx > maxEdge)
                continue;
            if(dis[nextstate % 2][x.u] <= dis[state % 2][u] + x.w)
                continue;
            dis[nextstate % 2][x.u] = dis[state % 2][u] + x.w;
            dijk.push({x.u, dis[nextstate % 2][x.u], nextstate, 0});
        }
    }
    return dis[0][en];
}

void solve() {
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w, 0, i});
        g[v].push_back({u, w, 0, i});
    }
    int shortestPath = dijkstra(1, n, m);
    int l = 1, r = m;
    while(l < r) {
        int mid = l + (r - l) / 2;
        int thisShortestPath = dijkstra(1, n, mid);
        if(thisShortestPath == shortestPath)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << " " << shortestPath << "\n";
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
5 10
4 5 7
3 2 1
3 5 5
5 2 5
1 4 6
2 1 1
4 3 7
1 3 7
4 2 4
1 5 8
*/
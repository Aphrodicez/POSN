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
    int u, w, edgeIdx;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

int dis[N];

vector <int> peattRoute;
map <int, pair <int, int>> peattEdge;

void solve() {
    peattRoute.clear();
    peattEdge.clear();
    while(!dijk.empty())
        dijk.pop();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dis[i] = 1e9;
        g[i].clear();
    }
    int st, en, startTime, peattNode;
    cin >> st >> en >> startTime >> peattNode;
    int u, v, w;
    for(int i = 1; i <= peattNode; i++) {
        cin >> u;
        peattRoute.push_back(u);
    }
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w, i});
        g[v].push_back({u, w, i});
    }
    dijk.push({peattRoute[0], 0});
    int i = 0;
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        dijk.pop();
        if(i == peattRoute.size() - 1) {
            break;
        }
        for(auto x: g[u]) {
            if(x.u != peattRoute[i + 1])
                continue;
            peattEdge[x.edgeIdx] = make_pair(w, w + x.w);
            dijk.push({x.u, w + x.w});
            i++;
            break;
        }
    }
    dis[st] = startTime;
    dijk.push({st, startTime});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        dijk.pop();
        if(u == en) {
            cout << w - startTime << "\n";
            return ;
        }
        for(auto x: g[u]) {
            int nextw = w + x.w;
            if(peattEdge.find(x.edgeIdx) != peattEdge.end()) {
                if(w >= peattEdge[x.edgeIdx].first && w < peattEdge[x.edgeIdx].second)
                    nextw = peattEdge[x.edgeIdx].second + x.w;
            }
            if(dis[x.u] <= nextw)
                continue;
            dis[x.u] = nextw;
            dijk.push({x.u, nextw});
        }
    }
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
6 5
1 6 20 4
5 3 2 4
1 2 2
2 3 8
2 4 3
3 5 15
3 6 10
8 9
1 5 5 5
1 2 3 4 5
1 2 8
2 3 10
2 7 4
3 4 23
3 6 5
4 8 4
4 5 5
6 8 3
6 7 40
*/
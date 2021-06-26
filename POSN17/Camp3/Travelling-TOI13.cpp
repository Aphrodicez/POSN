/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm Double Source
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
    int u, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e4 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

vector <int> disst, disen;

void solve() {
    int n, m;
    cin >> n >> m;
    int st, en, timeLimit;
    cin >> st >> en >> timeLimit;
    int u, v, w;
    disst.assign(N, 1e9);
    disen.assign(N, 1e9);
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    disst[st] = 0;
    dijk.push({st, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        dijk.pop();
        for(auto x: g[u]) {
            if(disst[u] + x.w > timeLimit)
                continue;
            if(disst[x.u] <= disst[u] + x.w)
                continue;
            disst[x.u] = disst[u] + x.w;
            dijk.push({x.u, disst[x.u]});
        }
    }
    disen[en] = 0;
    dijk.push({en, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        dijk.pop();
        for(auto x: g[u]) {
            if(disen[x.u] <= disen[u] + x.w)
                continue;
            disen[x.u] = disen[u] + x.w;
            dijk.push({x.u, disen[x.u]});
        }
    }
    int ans, minCostFromEn = 1e9;
    for(int i = 0; i < n; i++) {
        if(disst[i] <= timeLimit && disen[i] < minCostFromEn) {
            minCostFromEn = disen[i];
            ans = i;
        }
    }
    cout << ans << " " << disst[ans] << " " << disen[ans] << "\n";
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
8 11
0 5 200
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20

8 11
0 5 45
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/
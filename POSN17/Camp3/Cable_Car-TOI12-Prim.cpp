/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Maximum Spanning Tree [Prim]
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
        return w < o.w;
    }
};

const int N = 2500 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

priority_queue <GRAPH> pq;

bool visited[N];

void solve() {
    memset(visited, false, sizeof (visited));
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w - 1});
        g[v].push_back({u, w - 1});
    }
    int st, en, people;
    cin >> st >> en >> people;
    int chooseEdge = 1e9;
    pq.push({st, (int)1e9});
    while(!pq.empty()) {
        int u = pq.top().u;
        int w = pq.top().w;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        chooseEdge = min(chooseEdge, w);
        if(visited[en])
            break;
        for(auto x: g[u]) {
            if(visited[x.u])
                continue;
            pq.push({x.u, x.w});
        }
    }
    int ans = people / chooseEdge + (people % chooseEdge != 0);
    cout << ans << "\n";
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
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/
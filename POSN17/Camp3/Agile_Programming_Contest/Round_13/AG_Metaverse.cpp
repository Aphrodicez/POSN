/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)
#define x first
#define y second

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    int u, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

int distance(int x1, int y1, int x2, int y2) {
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    if(dx > dy)
        return dx;
    return dy + (dx % 2 != dy % 2);
}
 
pair <int, int> node[2 * MaxN];
vector <GRAPH> adj[2 * MaxN];
int dis[2 * MaxN];
priority_queue <GRAPH> pq;

void solve() {
    int m, q;
    scanf("%d %d", &m, &q);
    int n = 2 * m + 2;
    for(int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int u = 2 * i, v = 2 * i + 1;
        node[u] = make_pair(x1, y1);
        node[v] = make_pair(x2, y2);
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            int u = 2 * i, v = 2 * j;
            if(i == j)
                continue;
            adj[u].push_back({v, distance(node[u].x, node[u].y, node[v].x, node[v].y)});
            adj[u].push_back({v + 1, distance(node[u].x, node[u].y, node[v + 1].x, node[v + 1].y)});
            adj[u + 1].push_back({v, distance(node[u + 1].x, node[u + 1].y, node[v].x, node[v].y)});
            adj[u + 1].push_back({v + 1, distance(node[u + 1].x, node[u + 1].y, node[v + 1].x, node[v + 1].y)});
        }
    }
    while(q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        node[1] = make_pair(x1, y1);
        node[n] = make_pair(x2, y2);
        adj[1].push_back({n, distance(node[1].x, node[1].y, node[n].x, node[n].y)});
        adj[n].push_back({1, distance(node[n].x, node[n].y, node[1].x, node[1].y)});
        for(int i = 2; i <= n - 1; i++) {
            int u;
            int v = i;
            u = 1;
            adj[u].push_back({v, distance(node[u].x, node[u].y, node[v].x, node[v].y)});
            adj[v].push_back({u, distance(node[v].x, node[v].y, node[u].x, node[u].y)});
            ///
            u = n;
            adj[u].push_back({v, distance(node[u].x, node[u].y, node[v].x, node[v].y)});
            adj[v].push_back({u, distance(node[v].x, node[v].y, node[u].x, node[u].y)});
        }
        while(!pq.empty()) {
            pq.pop();
        }
        for(int i = 1; i <= n; i++) {
            dis[i] = 1e9;
        }
        dis[1] = 0;
        pq.push({1, 0});
        while(!pq.empty()) {
            int u = pq.top().u;
            pq.pop();
            if(u == n) {
                printf("%d\n", dis[u]);
                break;
            }
            for(auto x : adj[u]) {
                int nextw = dis[u] + x.w;
                if(dis[x.u] <= nextw)
                    continue;
                dis[x.u] = nextw;
                pq.push({x.u, nextw});
            }
        }
        adj[1].clear();
        adj[n].clear();
        for(int i = 2; i <= n - 1; i++) {
            adj[i].pop_back();
            adj[i].pop_back();
        }
    }
}

int main() {
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
0 1
0 0 0 1

1 2
0 0 10 10
1 0 11 10
10 0 11 2
*/
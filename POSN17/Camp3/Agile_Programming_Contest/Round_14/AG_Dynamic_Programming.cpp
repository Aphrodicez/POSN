/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm Kth State
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    int u, w, state;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

vector <GRAPH> adj[MaxN];
int dis[2][MaxN];
priority_queue <GRAPH> pq;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= 1; i++) {
        fill(dis[i] + 1, dis[i] + 1 + n, 1e9);
    }
    int st, en;
    scanf("%d %d", &st, &en);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
    }
    dis[0][st] = 0;
    pq.push({st, 0});
    while(!pq.empty()) {
        int u = pq.top().u;
        int w = pq.top().w;
        pq.pop();
        if(w > dis[1][u])
            continue;
        for(auto x : adj[u]) {
            int nextw = w + x.w;
            if(dis[0][x.u] == nextw)
                continue;
            if(dis[0][x.u] > nextw) {
                swap(dis[0][x.u], dis[1][x.u]);
                dis[0][x.u] = nextw;
                pq.push({x.u, dis[0][x.u]});
            }
            else if(dis[1][x.u] > nextw) {
                dis[1][x.u] = nextw;
                pq.push({x.u, dis[1][x.u]});
            }
        }
    }
    printf("%d\n", dis[1][en]);
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
3 3
1 3
1 2 1
1 2 2
2 3 1

4 5
1 2
1 2 4
1 3 1
3 2 3
1 4 2
4 2 3
*/
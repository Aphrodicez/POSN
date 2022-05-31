/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dijkstra Kth State + Bitmasking
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct GRAPH {
    int u, w, mask;
    bool operator <(const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e4 + 10;

vector <GRAPH> adj[MaxN];
priority_queue <GRAPH> pq;
int dis[1 << 8][MaxN];

int main() {
    int n, m, st, q;
    scanf("%d %d %d %d", &n, &m, &st, &q);
    for(int i = 1; i <= m; i++) {
        int u, v, w, x;
        scanf("%d %d %d %d", &u, &v, &w, &x);
        x--;
        adj[u].push_back({v, w, x});
        adj[v].push_back({u, w, x});
    }
    for(int mask = 0; mask < (1 << 8); mask++) {
        for(int u = 1; u <= n; u++) {
            dis[mask][u] = 1e9;
        }
    }
    dis[0][st] = 0;
    pq.push({st, 0, 0});
    while(!pq.empty()) {
        int u = pq.top().u;
        int w = pq.top().w;
        int mask = pq.top().mask;
        pq.pop();
        for(auto x : adj[u]) {
            int nextw = w + x.w;
            int nextmask = mask | (1 << x.mask);
            if(dis[nextmask][x.u] <= nextw)
                continue;
            dis[nextmask][x.u] = nextw;
            pq.push({x.u, nextw, nextmask});
        }
    }
    while(q--) {
        int en;
        scanf("%d", &en);
        int k;
        scanf("%d", &k);
        int mask = 0;
        for(int i = 1; i <= k; i++) {
            int x;
            scanf("%d", &x);
            x--;
            mask |= (1 << x);
        }
        int ans = 1e9;
        for(int i = 0; i < (1 << 8); i++) {
            if(mask & i)
                continue;
            ans = min(ans, dis[i][en]);
        }
        printf("%d\n", ans == 1e9 ? -1 : ans);
    }
    return 0;
}

/*
4 5 1 2
1 2 5 2
1 4 8 4
2 4 3 1
2 3 6 1
3 4 1 3
3 1 3
3 2 1 3
*/
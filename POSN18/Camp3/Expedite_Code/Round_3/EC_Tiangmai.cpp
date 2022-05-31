/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Minimum Spanning Tree
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct GRAPH {
    int u, v, w, q;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e5 + 10;
const int MaxQ = 2e5 + 10;

int parent[MaxN];
int ans[MaxQ];

int find_root(int u) {
    if(parent[u] == u)
        return u;
    return parent[u] = find_root(parent[u]);
}

priority_queue <GRAPH> pq;
priority_queue <GRAPH> Q;

void solve() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        pq.push({u, v, w});
    }
    for(int i = 1; i <= q; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Q.push({u, v, w, i});
    }
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    while(!Q.empty()) {
        while(!pq.empty() && pq.top().w <= Q.top().w) {
            int u = pq.top().u;
            int v = pq.top().v;
            int w = pq.top().w;
            pq.pop();
            int ru = find_root(u);
            int rv = find_root(v);
            if(ru == rv)
                continue;
            parent[ru] = rv;
        }
        int u = Q.top().u;
        int v = Q.top().v;
        int w = Q.top().w;
        int q = Q.top().q;
        Q.pop();
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            ans[q] = 1;
    }
    for(int i = 1; i <= q; i++) {
        if(ans[i])
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main() {
    int q = 1;

    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/*

*/
/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Minimum Spanning Tree + Dynamic Programming On Tree
    Status	: Wrong Answer [52]
*/

#include <bits/stdc++.h>
using namespace std;

struct MST {
    int u, v, w, i;
    bool operator < (const MST &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e5 + 10;

int parent[MaxN];

int find_root(int u) {
    if(parent[u] == u)
        return u;
    return parent[u] = find_root(parent[u]);
}

long long dp[MaxN];

priority_queue <MST> pq;

long long ans[MaxN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &dp[i]);
    }
    for(int i = 1; i <= n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        pq.push({u, v, w, i});
    }
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    while(!pq.empty()) {
        int u = pq.top().u;
        int v = pq.top().v;
        int w = pq.top().w;
        int i = pq.top().i;
        pq.pop();
        int rp = find_root(u);
        int rc = find_root(v);
        if(dp[rp] < dp[rc])
            swap(rp, rc);
        ans[i] = dp[rp] * dp[rc];
        parent[rc] = rp;
    }
    for(int i = 1; i <= n - 1; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}

/*
6
2 4 6 2 5 3
3 5 5
4 1 2
6 3 3
1 5 1
2 4 4
*/
/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm + Breadth First Search + Brute Force Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e3 + 10;

vector <int> adj[MaxN];
queue <int> qu;

int p[MaxN];
int deg[MaxN];
int dp[MaxN];

int n;

void reset() {
    for(int i = 1; i <= n; i++) {
        p[i] = -1;
        deg[i] = 0;
        dp[i] = 1;
    }
}

int bfs(int root) {
    reset();
    p[root] = 0;
    qu.emplace(root);
    int cnt = 0;
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        cnt++;
        for(auto x : adj[u]) {
            if(p[x] != -1)
                continue;
            deg[u]++;
            p[x] = u;
            qu.emplace(x);
        }
    }
    if(cnt != n)
        return 1e9;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0)
            qu.emplace(i);
    }
    int sum = 0;
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        sum += dp[u];
        dp[p[u]] += dp[u];
        if(--deg[p[u]] == 0)
            qu.emplace(p[u]);
    }
    return sum;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; j++) {
            int u;
            scanf("%d", &u);
            adj[u].emplace_back(i);
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, bfs(i));
    }
    printf("%d\n", ans);
    return 0;
}

/*
4
1 4
3 1 3 4
2 1 2
1 3
*/
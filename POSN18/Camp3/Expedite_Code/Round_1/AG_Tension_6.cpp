/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

#define u first
#define w second

pair <int, int> ans = make_pair(MaxN, MaxN);

vector <pair <int, int>> adj[MaxN];

int dp[MaxN];

void dfs(int u, int p) {
    for(auto x : adj[u]) {
        if(x.u == p)
            continue;
        dfs(x.u, u);
        dp[u] += x.w + dp[x.u];
    }
}

void dfs2(int u, int p, int sum) {
    dp[u] = sum + dp[u];
    ans = min(ans, make_pair(dp[u], u));
    for(auto x : adj[u]) {
        if(x.u == p)
            continue;
        dfs2(x.u, u, dp[u] - dp[x.u] + (x.w == 1 ? -1 : 1));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(make_pair(v, 0));
        adj[v].emplace_back(make_pair(u, 1));
    }
    dfs(1, 1);
    dfs2(1, 1, 0);
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}

/*
6
3 1
4 5
4 2
1 6
6 2
*/
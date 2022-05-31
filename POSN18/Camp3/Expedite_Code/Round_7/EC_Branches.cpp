/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming On Tree + Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

vector <int> adj[MaxN];

vector <int> ans;

int dfs(int u, int p) {
    int mx = -1;
    for(int x : adj[u]) {
        if(x == p)
            continue;
        int sum = dfs(x, u);
        if(mx == -1) {
            mx = sum;
            continue;
        }
        ans.emplace_back(min(mx, sum));
        mx = max(mx, sum);
    }
    return 1 + max(0, mx);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    ans.emplace_back(dfs(1, 1));
    sort(ans.begin(), ans.end(), greater <int>());
    printf("%d\n", (int)ans.size());
    for(int x : ans) {
        printf("%d\n", x);
    }
    return 0;
}

/*
7
1 2
1 3
3 4
3 6
5 4
7 6
*/
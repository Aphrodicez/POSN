/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int cost[10010];

vector <int> g[10010];

int dp[10010][3];

void dfs(int u, int p){
    int sum2 = 0, mi = 1e9;
    dp[u][1] += cost[u];
    for(auto x: g[u]){
        if(x==p)
            continue;
        dfs(x, u);
        sum2 += dp[x][2];
        dp[u][1] += min(dp[x][0], dp[x][2]);
        mi = min(mi, dp[x][1] - dp[x][2]);
    }
    dp[u][0] = sum2;
    dp[u][2] = min(dp[u][1], sum2 + mi);
}

int main(){
    setIO();
    int n, u, v;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    cout << dp[1][2];
    return 0;
}
/*
6
4
9
1
20
5
3
2 1
3 2
2 4
5 4
4 6
*/
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

vector <int> ans;

vector <int> g[100010];

int dp[100010];

void dfs(int u, int p){
    dp[u] = 1;
    if(g[u].size()==1)
        return;
    int idx, mx = -1e9;
    for(int x: g[u]){
        if(x==p)
            continue;
        dfs(x, u);
        if(mx < dp[x]){
            mx = dp[x];
            idx = x;
        }
    }
    dp[u] += dp[idx];
    for(auto x : g[u]){
        if(x==p || x==idx)
            continue;
        ans.push_back(dp[x]);
    }
}

int main(){
    setIO();
    int n, i, u, v;
    scanf("%d", &n);
    for(i=0; i<n-1; i++){
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    /*for(i=1; i<=n; i++){
        printf("%d ",dp[i]);
    }*/
    ans.push_back(dp[1]);
    sort(ans.begin(), ans.end(), greater<int>());
    printf("%d\n", ans.size());
    for(int x : ans){
        printf("%d\n", x);
    }
    return 0;
}
/*
7
1 2
1 3
3 4
4 5
3 6
6 7
*/
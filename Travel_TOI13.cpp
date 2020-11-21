/*
    TASK    : Travel_TOI13
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

struct A{
    int u, w;
    bool operator < (const A& o) const{
        return w > o.w;
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m, st, en, i, lim, u, v, w, ans, mx = 1e9 + 10;

int dis[10010], dis2[10010];

vector <A> g[100010];

priority_queue<A> dijk;

A now;

int main(){
    setIO();
    cin >> n >> m;
    cin >> st >> en >> lim;
    for(i=1; i<=m; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(i=0; i<n; i++){
        dis[i] = dis2[i] = 1e9 + 5;
    }
    dis[st] = 0;
    dijk.push({st, 0});
    while(!dijk.empty()){
        now = dijk.top();
        dijk.pop();
        for(auto x: g[now.u]){
            if(dis[x.u]<=dis[now.u] + x.w)
                continue;
            dis[x.u] = dis[now.u] + x.w;
            dijk.push({x.u, dis[x.u]});
        }
    }
    for(i=0; i<n; i++){
        cout << dis[i] << " ";
    }
    if(dis[en] <= lim){
        cout << en << " " << dis[en] << " " << 0;
        return 0;
    }
    dis2[en] = 0;
    dijk.push({en, 0});
    while(!dijk.empty()){
        now = dijk.top();
        dijk.pop();
        for(auto x: g[now.u]){
            if(dis2[x.u] <= dis2[now.u] + x.w)
                continue;
            dis2[x.u] = dis2[now.u] + x.w;
            dijk.push({x.u, dis2[x.u]});
        }
    }
    for(i=n-1; i>=0; i--){
        if(dis[i] <= lim && dis2[i] <= mx){
            mx = dis2[i];
            ans = i;
        }
    }
    cout << ans << " " << dis[ans] << " " << dis2[ans];
    return 0;
}
/*
8 11
0 5 200
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/
/*
8 11
0 5 40
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/

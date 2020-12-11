/*
    TASK    : AP_Convoke
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/

#include <bits/stdc++.h>
using namespace std;

struct A{
    int u, w, nowbit;
    bool operator < (const A& o) const{
        return w > o.w;
    }
};

priority_queue<A> dijk;

int mask_dis[1 << 16][210], dis[210][210], pick[210], bw[16];
vector<A> g[210];

A now;

int main()
{
    int n, m, k, u, v, w, i, j, mid, mn = 1<<22;
    cin >> n >> m >> k;
    memset(pick, -1, sizeof pick);
    bw[0] = 1;
    for(i=1; i<=15; i++){
        bw[i] = bw[i-1] * 2;
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            mask_dis[i][j] = 1<<22;
        }
        mask_dis[i][i] = 0;
    }
    for(i=0; i<k; i++){
        cin >> u;
        pick[u] = i;
    }
    for(i=0;i<m;i++){
        cin >> u >> v >> w;
        mask_dis[u][v] = mask_dis[v][u] = w;
    }
    for(mid=1; mid<=n; mid++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                mask_dis[i][j] = min(mask_dis[i][j], mask_dis[i][mid] + mask_dis[mid][j]);
            }
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if((i==1 || i==n || pick[i] != -1) && (j==1 || j==n || pick[j] != -1) && i != j){
                g[i].push_back({j, mask_dis[i][j], 0});
            }
        }
    }
    for(i=0; i<bw[k]; i++){
        for(j=1; j<=n; j++){
            dis[i][j]=1<<22;
        }
    }
    dis[0][1] = 0;
    dijk.push({1, 0, 0});
    while(!dijk.empty()){
        now = dijk.top();
        dijk.pop();
        if(now.nowbit == (bw[k])-1 && now.u==n){
            cout << now.w;
            return 0;
        }
        for(auto x : g[now.u]){
            if(pick[x.u]!=-1){
                if(dis[now.nowbit|(bw[pick[x.u]])][x.u] > x.w + now.w){
                    dis[now.nowbit|(bw[pick[x.u]])][x.u] = x.w + now.w;
                    dijk.push({x.u, x.w+now.w, now.nowbit|(bw[pick[x.u]])});
                }
            }
            else if(dis[now.nowbit][x.u] > x.w + now.w){
                dis[now.nowbit][x.u] = x.w + now.w;
                dijk.push({x.u, x.w + now.w, now.nowbit});
            }
        }
    }
}
/*
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
*/

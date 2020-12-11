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

struct A{
    int u, w, nowbit;
    bool operator < (const A& o) const{
        return w > o.w;
    }
};


int bw[20], fws[210][210], pick[210], dis[210][1 << 16];

vector <A> g[210];

priority_queue <A> dijk;

A now;

int main(){
    setIO();
    int n, m, k, idx, u, v, w;
    cin >> n >> m >> k;
    memset(pick , -1, sizeof pick);
    bw[0] = 1;
    for(int i=1; i<=17; i++){
        bw[i] = bw[i-1] * 2;
    }

    for(int i = 0; i < k; i++){
        cin >> idx;
        pick[idx] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            fws[i][j] = 1e9;
        }
        fws[i][i] = 0;
    }

    for(int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        fws[u][v] = fws[v][u] =  w;
    }

    for(int mid = 1; mid <= n; mid++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                fws[i][j] = min(fws[i][j], fws[i][mid] + fws[mid][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i==1 || i == n || pick[i] != -1) && (j == 1 || j == n || pick[j] != -1) && (i != j)){
                g[i].push_back({j, fws[i][j]});
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j = 0; j < bw[k]; j++)
            dis[i][j] = 1e9;
    }

    dis[1][0] = 0;
    dijk.push({1, 0, 0});

    while(!dijk.empty()){
        now = dijk.top();
        dijk.pop();
        if(now.u == n && now.nowbit == bw[k] - 1){
            cout << dis[n][now.nowbit];
            return 0;
        }
        for(auto x: g[now.u]){
            if(pick[x.u] != -1){
                if(dis[x.u][bw[pick[x.u]] | now.nowbit] <= dis[now.u][now.nowbit] + x.w)
                    continue;
                dis[x.u][bw[pick[x.u]] | now.nowbit] = dis[now.u][now.nowbit] + x.w;
                dijk.push({x.u, dis[x.u][bw[pick[x.u]] | now.nowbit], bw[pick[x.u]]| now.nowbit });
            }
            else{
                if(dis[x.u][now.nowbit] <= dis[now.u][now.nowbit] + x.w)
                    continue;
                dis[x.u][now.nowbit] = dis[now.u][now.nowbit] + x.w;
                dijk.push({x.u, dis[x.u][now.nowbit], now.nowbit});
            }
        }
    }
    return 0;
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

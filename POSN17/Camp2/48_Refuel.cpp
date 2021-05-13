/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Dijkstra's Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct DIJK{
    int u, w, fuel;
    DIJK (int tmpu, int tmpw, int tmpfuel){
        u = tmpu;
        w = tmpw;
        fuel = tmpfuel;
    }
    bool operator < (const DIJK &o) const{
        return w > o.w;
    }
};

#define eb emplace_back
#define v(a) vector <a>
#define heap(a) priority_queue<a>

const int N = 1e3 + 10;
const int M = 1e4 + 10;
const int CAPA = 1e2 + 10;

int cost[N];

int dis[CAPA][N];

v(DIJK) g[N];

heap(DIJK) dijk;

void solve() {
    while(!dijk.empty())
        dijk.pop();
    int n, m, u, v, w, capa, st, en;
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n - 1; i++){
        g[i].clear();
        scanf("%d", &cost[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        g[u].eb(v, w, 0);
        g[v].eb(u, w, 0);
    }
    scanf("%d %d %d", &capa, &st, &en);
    for(int k = 0; k <= capa; k++){
        for(int i = 0; i <= n - 1; i++){
            dis[k][i] = 1e9;
        }
    }
    dis[0][st] = 0;
    dijk.push({st, 0, 0});
    while(!dijk.empty()){
        int u = dijk.top().u;
        int w = dijk.top().w;
        int fuel = dijk.top().fuel;
        dijk.pop();
        if(u == en){
            printf("%d\n", dis[fuel][u]);
            return ;
        }
        if( (fuel + 1 <= capa) && (dis[fuel + 1][u] > dis[fuel][u] + cost[u]) ){
            dis[fuel + 1][u] = dis[fuel][u] + cost[u];
            dijk.push({u, dis[fuel + 1][u], fuel + 1});
        }
        for(auto &x : g[u]){
            if(fuel - x.w < 0)
                continue;
            if(dis[fuel - x.w][x.u] <= dis[fuel][u])
                continue;
            dis[fuel - x.w][x.u] = dis[fuel][u];
            dijk.push({x.u, dis[fuel - x.w][x.u], fuel - x.w});
        }
    }
    printf("-99\n");
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
20 1 4
*/
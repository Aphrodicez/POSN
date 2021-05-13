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
    int u, w, fuel, ticket;
    DIJK (int tmpu, int tmpw, int tmpfuel, int tmptick){
        u = tmpu;
        w = tmpw;
        fuel = tmpfuel;
        ticket = tmptick;
    }
    bool operator < (const DIJK &o) const{
        return w > o.w;
    }
};

#define eb emplace_back
#define v(a) vector <a>
#define heap(a) priority_queue<a>

const int N = 1e2 + 10;
const int M = 5e3 + 10;
const int CAPA = 1e2 + 10;

int cost[N];

int dis[2][CAPA][N];

v(DIJK) g[N];

heap(DIJK) dijk;

void solve() {
    int n, m, u, v, w, st, en, capa;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &cost[i]);
    }
    scanf("%d %d %d", &st, &en, &capa);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        g[u].eb(v, w, 0, 0);
        g[v].eb(u, w, 0, 0);
    }
    for(int k = 0; k <= capa; k++){
        for(int i = 1; i <= n; i++){
            dis[0][k][i] = dis[1][k][i] = 1e9;
        }
    }
    dis[0][0][st] = 0;
    dijk.push({st, 0, 0, 0});
    while(!dijk.empty()){
        int u = dijk.top().u;
        int w = dijk.top().w;
        int fuel = dijk.top().fuel;
        int ticket = dijk.top().ticket;
        dijk.pop();
        if(u == en && fuel == capa){
            printf("%d\n", w);
            return ;
        }
        if( (!ticket) && (fuel <= capa) && dis[ticket + 1][capa][u] > dis[ticket][fuel][u]){
            dis[ticket + 1][capa][u] = dis[ticket][fuel][u];
            dijk.push({u, dis[ticket + 1][capa][u], capa, ticket + 1});
        }
        if(fuel + 1 <= capa && (dis[ticket][fuel + 1][u] > dis[ticket][fuel][u] + cost[u])){
            dis[ticket][fuel + 1][u] = dis[ticket][fuel][u] + cost[u];
            dijk.push({u, dis[ticket][fuel + 1][u], fuel + 1, ticket});
        }
        for(auto &x : g[u]){
            if(fuel < x.w)
                continue;
            if(dis[ticket][fuel - x.w][x.u] <= dis[ticket][fuel][u])
                continue;
            dis[ticket][fuel - x.w][x.u] = dis[ticket][fuel][u];
            dijk.push({x.u, dis[ticket][fuel - x.w][x.u], fuel - x.w, ticket});
        }
    }
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4
7 1 8 10
1 4 100
5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20

5
10 1 3 10 30
1 4 20
4
1 2 1
1 5 5
4 5 20
3 4 2
*/
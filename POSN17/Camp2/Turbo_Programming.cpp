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

struct EDGE{
    int u, w;
    EDGE(int tmpu, int tmpw){
        u = tmpu;
        w = tmpw;
    }
    bool operator < (const EDGE &o) const{
        return w > o.w;
    }
};

#define eb emplace_back
#define v(a) vector <a>
#define heap(a) priority_queue <a>

const int N = 1e3 + 10;
const int M = 1e5 + 10;

int dis[N];
v(EDGE) g[N];
heap(EDGE) he;

void testcase(){
    int u;
    scanf("%d", &u);
    if(dis[u] == 1e9){
        printf("-1\n");
        return ;
    }
    printf("%d\n", dis[u]);
}

void solve() {
    int n, m, u, v, w, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
        dis[i] = 1e9;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        g[u].eb(v, w);
    }
    dis[1] = 0;
    he.push({1, 0});
    while(!he.empty()){
        int u = he.top().u;
        int w = he.top().w;
        he.pop();
        for(auto &x : g[u]){
            if(dis[x.u] <= dis[u] + x.w)
                continue;
            dis[x.u] = dis[u] + x.w;
            he.push({x.u, dis[x.u]});
        }
    };
    while(q--){
        testcase();
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
6 5 3
1 2 10
2 3 10
3 4 10
4 5 10
1 5 50
6
5
4
*/
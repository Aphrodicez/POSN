/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Floyd Warshall's Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

#define v(a) vector <a>
#define eb emplace_back

const int N = 3e2 + 10;
const int M = 1e4 + 10;

v(int) g[N];

int dis[N][N];

void solve() {
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dis[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for(int mid = 1; mid <= n; mid++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                if(dis[u][mid] == 1e9)
                    continue;
                if(dis[u][v] <= dis[u][mid] + dis[mid][v])
                    continue;
                dis[u][v] = dis[u][mid] + dis[mid][v];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dis[i][j] == 1e9){
                printf("0 ");
                continue;
            }
            printf("%d ", dis[i][j]);
        }
        printf("\n");
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
4 5
1 2 10
2 3 10
1 3 15
4 4 10
4 1 10
*/
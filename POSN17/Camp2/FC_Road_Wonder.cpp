/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Bellman Ford's Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct EDGE{
    int u, v, w;
};

const int N = 1e3 + 10;
const int M = 1e3 + 10;

EDGE edge[M];

int dis[N], tmp[N];

void testcase(int n, int m){
    int st, u, v, w;
    scanf("%d", &st);
    for(int i = 1; i <= n; i++){
        dis[i] = 1e9;
    }
    dis[st] = 0;
    for(int k = 1; k <= n - 1; k++){
        for(int i = 1; i <= m; i++){
            int u = edge[i].u;
            int v = edge[i].v;
            int w = edge[i].w;
            if(dis[u] == 1e9)
                continue;
            if(dis[v] <= dis[u] + w)
                continue;
            dis[v] = dis[u] + w;
        }
    }
    for(int i = 1; i <= n; i++)
        tmp[i] = dis[i];
    for(int i = 1; i <= m; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        if(dis[u] == 1e9)
            continue;
        if(dis[v] <= dis[u] + w)
            continue;
        dis[v] = dis[u] + w;
    }
    for(int i = 1; i <= n; i++){
        if(dis[i] == 1e9 || tmp[i] != dis[i]){
            printf("-1 ");
            continue;
        }
        printf("%d ", dis[i]);
    }
    printf("\n");
}

void solve() {
    int n, m, k, q, u, v, w;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &w);
        edge[i] = {u, v, w};
    }
    for(int i = 1; i <= k; i++){
        scanf("%d %d %d", &u, &v, &w);
        edge[m + i] = {u, v, -w};
    }
    while(q--){
        testcase(n, m + k);
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
10 5 5 5
1 7 8
2 5 1
3 4 7
5 8 4
5 1 11
10 1 6
10 5 3
10 3 1
9 5 10
5 7 2
2
4
6
8
10
*/
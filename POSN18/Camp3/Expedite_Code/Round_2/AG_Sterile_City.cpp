/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Floyd-Warshall Algorithm + Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e2 + 10;

int nodes[MaxN];
int dis[MaxN][MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = 1e9;
            }
        }
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            dis[u][v] = dis[v][u] = min(dis[u][v], w);
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        for(int i = 1; i <= k; i++) {
            scanf("%d", &nodes[i]);
        }
        pair <int, pair <int, int>> mn = make_pair(1e9, make_pair(1e9, 1e9));
        for(int i = 1; i <= k; i++) {
            for(int j = i + 1; j <= k; j++) {
                mn = min(mn, make_pair(dis[nodes[i]][nodes[j]], make_pair(i, j)));
            }
        }
        int mn2 = 1e9;
        for(int i = 1; i <= k; i++) {
            for(int j = i + 1; j <= k; j++) {
                if(i == mn.second.first || i == mn.second.second || j == mn.second.first || j == mn.second.second)
                    continue;
                mn2 = min(mn2, dis[nodes[i]][nodes[j]]);       
            }
        }
        int ans = mn.first + mn2;
        printf("%d\n", ans);    
    }
    return 0;
}

/*
2
5 4 4
1 2 1
3 4 2
4 5 5
5 3 8
3 1 5 2
6 6 4
1 2 5
2 4 7
4 6 50
6 5 3
1 5 15
3 5 6
1 5 4 6
*/
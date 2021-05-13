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

const int N = 5e2 + 10;
const int M = 2e5 + 10;

int dis[N][N];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &dis[i][j]);
        }
    }
    for(int mid = 1; mid <= n; mid++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                if(!dis[u][mid])
                    continue;
                dis[u][v] |= (dis[u][mid] & dis[mid][v]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
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
4
0 0 1 0
1 0 0 1
0 0 0 0
0 1 0 0
*/
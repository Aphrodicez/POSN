/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dijkstra Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};

struct GRAPH {
    int i, j, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e3 + 10;

int a[MaxN][MaxN];

priority_queue <GRAPH> pq;
int dis[MaxN][MaxN];

void solve() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dis[i][j] = 1e9;
            scanf("%d", &a[i][j]);
        }
    }
    for(int j = 1; j <= c; j++) {
        dis[1][j] = a[1][j];
        pq.push({1, j, dis[1][j]});
    }
    while(!pq.empty()) {
        int i = pq.top().i;
        int j = pq.top().j;
        int w = pq.top().w;
        pq.pop();
        if(dis[i][j] < w)
            continue;
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || ii > r || jj < 1 || jj > c)
                continue;
            if(dis[ii][jj] <= dis[i][j] + a[ii][jj])
                continue;
            dis[ii][jj] = dis[i][j] + a[ii][jj];
            pq.push({ii, jj, dis[ii][jj]});
        }
    }
    int ans = 1e9;
    for(int j = 1; j <= c; j++) {
        ans = min(ans, dis[r][j]);
    }
    printf("%d\n", ans);
}

int main() {
    int q = 1;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/*

*/
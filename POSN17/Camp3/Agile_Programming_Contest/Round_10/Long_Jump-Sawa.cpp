/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search
    Status	: Rejected [25]
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN][MaxN];
int dis[MaxN][MaxN];

queue <tuple <int, int>> qu;

void solve() {
    int n, m, w;
    scanf("%d %d %d", &n, &m, &w);
    int stx, sty;
    scanf("%d %d", &stx, &sty);
    int enx, eny;
    scanf("%d %d", &enx, &eny);
    for(int i = 0; i <= n + 1; i++) {
        a[i][0] = a[i][m + 1] = 1;
    }
    for(int j = 0; j <= m + 1; j++) {
        a[0][j] = a[m + 1][j] = 1;
    }
    for(int i = 1; i <= w; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
    }
    qu.push(make_tuple(stx, sty));
    while(!qu.empty()) {
        int x, y;
        tie(x, y) = qu.front();
        qu.pop();
        if(x - 1 == 0 || a[x - 1][y]) {
            int j = y;
            for(int i = x + 1; i <= n && !a[i][j]; i++) {
                if(dis[i][j])
                    continue;
                dis[i][j] = dis[x][y] + 1;
                if(i == enx && j == eny) {
                    printf("%d\n", dis[i][j]);
                    return ;
                }
                qu.push(make_tuple(i, j));
            }
        }
        if(x == n || a[x + 1][y]) {
            int j = y;
            for(int i = x - 1; i >= 1 && !a[i][j]; i--) {
                if(dis[i][j])
                    continue;
                dis[i][j] = dis[x][y] + 1;
                if(i == enx && j == eny) {
                    printf("%d\n", dis[i][j]);
                    return ;
                }
                qu.push(make_tuple(i, j));
            }
        }
        if(y == 1 || a[x][y - 1]) {
            int i = x;
            for(int j = y + 1; j <= m && !a[i][j]; j++) {
                if(dis[i][j])
                    continue;
                dis[i][j] = dis[x][y] + 1;
                if(i == enx && j == eny) {
                    printf("%d\n", dis[i][j]);
                    return ;
                }
                qu.push(make_tuple(i, j));
            }  
        }
        if(y == m || a[x][y + 1]) {
            int i = x;
            for(int j = y - 1; j >= 1 && !a[i][j]; j--) {
                if(dis[i][j])
                    continue;
                dis[i][j] = dis[x][y] + 1;
                if(i == enx && j == eny) {
                    printf("%d\n", dis[i][j]);
                    return ;
                }
                qu.push(make_tuple(i, j));
            }  
        }
    }
    printf("-1\n");
}

int main() {
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
5 5 0
4 1
4 3
*/
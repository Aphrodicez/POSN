/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search
    Status	: Accepted
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

const int MaxN = 2e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN][MaxN];
bool visited[MaxN][MaxN];
queue <tuple <int, int>> qu;

int n;

void bfs(int sti, int stj) {
    int ans = a[sti][stj];
    visited[sti][stj] = true;
    qu.push(make_tuple(sti, stj));
    while(!qu.empty()) {
        int i, j;
        tie(i, j) = qu.front();
        qu.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > n || jj > n)
                continue;
            if(a[ii][jj] == 100)
                continue;
            if(a[ii][jj] <= a[i][j])
                continue;
            if(visited[ii][jj])
                continue;
            visited[ii][jj] = true;
            ans = max(ans, a[ii][jj]);
            qu.push(make_tuple(ii, jj));
        }
    }
    printf("%d\n", ans);
}

void solve() {
    scanf("%d", &n);
    int sti, stj;
    scanf("%d %d", &stj, &sti);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    bfs(sti, stj);
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
4
2 1
100 1 3 8
0 2 1 4
2 3 5 100
0 8 8 100

1
1 1
9

5
4 2
0 1 100 100 0
100 2 3 1 1
100 100 4 5 100
8 7 100 6 100
7 100 100 100 9
*/
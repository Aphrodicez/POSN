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

const int MaxN = 1e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {

};

int a[MaxN][MaxN];

queue <tuple <int, int, int>> qu;
int dis[MaxN][MaxN];

const int d6i[2][6] = {{-1, 0, 1, 1, 0, -1}, {-1, 0, 1, 1, 0, -1}};
const int d6j[2][6] = {{0, 1, 0, -1, -1, -1}, {1, 1, 1, 0, -1, 0}};

int r, c;
int sti, stj;
int eni, enj;

void bfs() {
    dis[sti][stj] = 0;
    qu.push(make_tuple(sti, stj, 0));
    while(!qu.empty()) {
        int i, j, w;
        tie(i, j, w) = qu.front();
        qu.pop();
        if(i == eni && j == enj) {
            printf("%d\n", w);
            return ;
        }
        int nextw = w + 1;
        for(int k = 0; k < 6; k++) {
            int ii = i + d6i[i & 1][k];
            int jj = j + d6j[i & 1][k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(!a[ii][jj])
                continue;
            if(nextw % a[ii][jj])
                continue;
            if(dis[ii][jj] == nextw)
                continue;
            dis[ii][jj] = nextw;
            qu.push(make_tuple(ii, jj, nextw));
        }
    }
}

void solve() {
    memset(dis, -1, sizeof dis);
    scanf("%d %d", &r, &c);
    sti = (r + 1) / 2, stj = 0;
    eni = (r + 1) / 2, enj = c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    bfs();
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
5
4
1 1 3 8
0 1 1 0
1 6 5 7
1 3 2 3
2 5 2 0

5
4
1 1 1 1
0 0 1 0
0 0 1 1
1 0 1 1
1 1 1 0

5
5
1 1 1 1 8
0 9 1 0 7
1 0 1 8 7
1 0 1 1 7
1 6 1 0 6
*/
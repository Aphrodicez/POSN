/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    int i, j, w;
};

const int N = 7e2 + 10;
const int M = 2e5 + 10;

queue <GRAPH> bfs;

char a[N][N];

int dis[N][N], mark[N][N];

void solve() {
    while(!bfs.empty())
        bfs.pop();
    memset(mark, 0, sizeof mark);
    int r, c, n, time, sti, stj;
    cin >> r >> c >> n >> time >> sti >> stj;
    sti++, stj++;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dis[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= n; i++) {
        int ti, ii, jj;
        cin >> ti >> ii >> jj;
        ii++, jj++;
        if(dis[ii][jj] <= ti)
            continue;
        dis[ii][jj] = ti;
        bfs.push({ii, jj});
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    while(!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj]=='#')
                continue;
            if(dis[ii][jj] <= dis[i][j] + 1)
                continue;
            dis[ii][jj] = dis[i][j] + 1;
            bfs.push({ii, jj});
        }
    }
    int ans = 0;
    mark[sti][stj] = 1;
    bfs.push({sti, stj, 0});
    while(!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        int w = bfs.front().w;
        bfs.pop();
        ans = max(dis[i][j], ans);
        for(int k = 0; k < 4; k++){
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(dis[ii][jj] <= w + 1)
                continue;
            if(mark[ii][jj])
                continue;
            mark[ii][jj] = 1;
            bfs.push({ii, jj, w + 1});
        }
    }
    if(ans - time > 0) {
        cout << "YES" << '\n';
        return ;
    }
    cout << "NO" << " " << ans - 1 << '\n';
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--) {
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
2 5 1 1 0 2
1 0 2
.....
.....
2 5 1 1 0 2
0 0 2
.....
.....
2 5 4 1 0 2
1 0 2
1 0 3
1 0 1
1 1 2
.....
.....
5 5 2 10 2 2
0 0 0
0 4 4
.....
.###.
.#.#.
.###.
.....
*/
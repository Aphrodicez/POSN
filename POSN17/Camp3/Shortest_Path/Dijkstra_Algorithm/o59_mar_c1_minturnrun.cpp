/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm
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
#define dec(x) fixed << setprecision(x)
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
    int i, j, w, state;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

const int di[] = {0, -1, 1};
const int dj[] = {1, 0, 0};
/// 0 = right, 1 = up, 2 = down

priority_queue <GRAPH> dijk;

void solve() {
    int r, c, sti;
    cin >> r >> c >> sti;
    char a[r + 1][c + 1];
    int dis[3][r + 1][c + 1];
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
            for(int k = 0; k < 3; k++)
                dis[k][i][j] = 1e9;
        }
    }
    dijk.push({sti, 1, 0, 0});
    dis[0][sti][1] = 0;
    while(!dijk.empty()) {
        int i = dijk.top().i;
        int j = dijk.top().j;
        int w = dijk.top().w;
        int state = dijk.top().state;
        dijk.pop();
        if(j == c) {
            cout << w << "\n";
            return ;
        }
        for(int k = 0; k < 3; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || ii > r || jj < 1 || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            int nextw = dis[state][i][j] + (state != k);
            if(dis[k][ii][jj] <= nextw)
                continue;
            dis[k][ii][jj] = nextw;
            dijk.push({ii, jj, dis[k][ii][jj], k});
        }
    }
    cout << -1 << "\n";
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
6 8 2
...#....
...#....
...#.#..
.....#..
........
........

6 12 2
...#...#...#
.....#.#.#.#
####.#...#.#
.....#.#.#..
...#########
............
*/
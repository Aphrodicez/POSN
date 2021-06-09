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
    int i, j;
};

const int N = 1e2 + 10;
const int M = 2e5 + 10;

int a[N][N];

int dis[N][N];

queue <GRAPH> bfs;

vector <GRAPH> g[N][N];

void solve() {
    memset(dis, -1, sizeof dis);
    int r, c;
    char now;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> now;
            if(now == 'R' || now == 'B') {
                g[i][j].pb({i, j + 1});
                g[i][j+1].pb({i, j});
            }
            if(now == 'D' || now == 'B') {
                g[i+1][j].pb({i, j});
                g[i][j].pb({i + 1, j});
            }
        }
    }
    dis[1][1] = 1;
    bfs.push({1, 1});
    while (!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        for(auto next: g[i][j]){
            if(dis[next.i][next.j] == dis[i][j] + 1){
                cout << dis[next.i][next.j] << '\n';
                cout << next.i << " " << next.j << '\n';
                return ;
            }
            if(dis[next.i][next.j] != -1)
                continue;
            dis[next.i][next.j] = dis[i][j] + 1;
            bfs.push({next.i, next.j});
        }
    }
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
4 4 
B R D N 
D R B D 
R R R D 
N N N N

3 4 
B B B D 
D N R B 
R R R N 
*/
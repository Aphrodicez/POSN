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

const int N = 3e1 + 10;
const int M = 2e5 + 10;

struct GRAPH{
    int i, j;
};

char a[N][N];

int dis[N][N];

queue <GRAPH> bfs;

void solve() {
    while(!bfs.empty())
        bfs.pop();
    memset(dis, -1, sizeof dis);
    int r, c, t;
    cin >> r >> c >> t;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }
    int sti, stj, eni, enj;
    int cnt = 0;
    cin >> sti >> stj >> eni >> enj;
    dis[sti][stj] = 0;
    bfs.push({sti, stj});
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        cnt++;
        for(int k = 0; k < 4; k++){
            int ii = i + d4i[k], jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(dis[ii][jj] != -1)
                continue;
            dis[ii][jj] = dis[i][j] + 1;
            bfs.push({ii, jj});
        }
    }
    t -= dis[eni][enj];
    if(t < 0 || dis[eni][enj] == -1) {
        cout << -1 << "\n";
        return;
    }
    cout << min(t / 2 + dis[eni][enj] + 1, cnt) << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
5 8 9 
#..#..#.
.#...##.
##.##..#
...##.##
##.#..##
4 3 2 4
4 5 100
.....
.####
...#.
#.##.
3 3 1 3
3 5 2
.....
.####
.....
3 3 1 3
*/
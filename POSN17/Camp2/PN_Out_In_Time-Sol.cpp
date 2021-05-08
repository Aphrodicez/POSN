/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct BFS{
    int i, j;
};

const int R = 40;
const int C = 40;

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

char a[R][C];
int dis[R][C];

queue <BFS> bfs;

vector <BFS> vec;

void solve() {
    vec.clear();
    while(!bfs.empty())
        bfs.pop();
    int r, c, t, sti, stj, eni, enj;
    cin >> r >> c >> t;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            dis[i][j] = 1e9;
            cin >> a[i][j];
        }
    }
    cin >> sti >> stj >> eni >> enj;
    dis[sti][stj] = 0;
    bfs.push({sti, stj});
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        vec.push_back({i, j});
        for(int k = 0; k < 4; k++){
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(dis[ii][jj] <= dis[i][j] + 1)
                continue;
            dis[ii][jj] = dis[i][j] + 1;
            bfs.push({ii, jj});
        }
    }
    if(t - dis[eni][enj] < 0){
        cout << "-1\n";
        return;
    }
    t -= dis[eni][enj];
    int ans = min(dis[eni][enj] + 1 + t / 2, (int)vec.size());
    cout << ans << "\n";
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
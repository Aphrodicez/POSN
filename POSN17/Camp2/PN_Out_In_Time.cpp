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
int mark[R][C], dis[R][C];

queue <BFS> bfs, bfs2;

void solve() {
    while(!bfs.empty())
        bfs.pop();
    while(!bfs2.empty())
        bfs2.pop();
    int r, c, t, sti, stj, eni, enj;
    cin >> r >> c >> t;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            dis[i][j] = 1e9;
            mark[i][j] = 0;
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
            if(ii == eni && jj == enj)
                break;
            bfs.push({ii, jj});
        }
    }
    if(t - dis[eni][enj] < 0){
        cout << "-1\n";
        return;
    }
    while(!bfs.empty())
        bfs.pop();
    mark[eni][enj] = 1;
    bfs.push({eni, enj});
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        bfs2.push({i, j});
        for(int k = 0; k < 4; k++){
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(dis[ii][jj] + 1 != dis[i][j])
                continue;
            mark[ii][jj] = 1;
            bfs.push({ii, jj});
        }
    }
    t -= dis[eni][enj];
    int ans = bfs2.size();
    while(!bfs2.empty()){
        int i = bfs2.front().i;
        int j = bfs2.front().j;
        bfs2.pop();
        for(int k = 0; k < 4; k++){
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(mark[ii][jj])
                continue;
            if(t - 2 < 0){
                cout << ans << "\n";
                return;
            }
            mark[ii][jj] = 1;
            ans++;
            t -= 2;
            bfs2.push({ii, jj});
        }
    }
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
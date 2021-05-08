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

const int R = 1e3 + 10;
const int C = 1e3 + 10;

char a[R][C];

int dis[R][C];

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

queue <BFS> bfs;

void solve() {
    int r, c, sti, stj, eni, enj;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            dis[i][j] = 1e9;
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                sti = i;
                stj = j;
            }
            if(a[i][j] == 'E'){
                eni = i;
                enj = j;
            }
        }
    }
    dis[eni][enj] = 0;
    bfs.push({eni, enj});
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
            bfs.push({ii, jj});
        }
    }
    if(dis[sti][stj] == 1e9){
        cout << -1 << "\n";
        return ;
    }
    int ans = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if( (isdigit(a[i][j])) && (a[i][j] - '0') && (dis[i][j] != 1e9) ){
                if(dis[i][j] <= dis[sti][stj]){
                    ans += a[i][j] - '0';
                }
            }
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
2
5 7
000E0#3
#0##0#0
050#0#0
4#0#0#0
0#0S000
1 4
SE69
*/
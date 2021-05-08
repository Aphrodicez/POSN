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

const int R = 2e3 + 10;
const int C = 2e3 + 10;

char a[R][C], s[C];

int dis[R][C];

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

queue <BFS> bfs;

void solve() {
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){      
        for(int j = 1; j <= c; j++){
            dis[i][j] = 1e9;
            cin >> a[i][j];
            if(a[i][j] == 'X'){
                dis[i][j] = 0;
                bfs.push({i, j});
            }
        }
    }
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int ii = i + di[k], jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == 'W')
                continue;
            if(dis[ii][jj] <= dis[i][j] + 1)
                continue;
            dis[ii][jj] = dis[i][j] + 1;
            bfs.push({ii, jj});
        }
    }
    int ans = 0, cnt = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if((a[i][j] == 'A') && (dis[i][j] != 1e9)){
                cnt++;
                ans += dis[i][j] * 2;
            }
        }
    } 
    cout << cnt << " " << ans << "\n";
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
5 5
EEEEE
AEAEW
WEEWW
WEEXE
WWEXA

5 5
WEEEE
AWAEW
WEEWW
WEEXE
WWEEE

5 9
EEEWEEEEE
EWEWEWEEE
AWXWEWWWE
EWWWEWEEE
EEEEEWAEE
*/
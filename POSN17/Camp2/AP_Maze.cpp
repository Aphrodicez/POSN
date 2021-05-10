/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Breadth First Search
    Status	: BUG
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct BFS{
    int i, j, state;
};

const int R = 3e2 + 10;
const int C = 3e2 + 10;

int laser[5][R][C], dis[R][C];

char a[R][C];

int di[] = {0, 0, -1, 1, 1, -1, -1, 1}, dj[] = {-1, 1, -1, 1, 0, 0, 1, -1};

int di4[] = {0, 0, 1, -1}, dj4[] = {1, -1, 0, 0};

char wall[] = {'-', '\\', '|', '/'};

queue <BFS> bfs;

void solve() {
    int r, c, sti, stj, eni, enj;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            for(int k = 0; k < 4; k++)
                laser[k][i][j] = 0;
            dis[i][j] = 1e9;
            cin >> a[i][j];
            for(int it = 0; it < 4; it++){
                if(wall[it] == a[i][j]){
                    bfs.push({i, j, it});
                    a[i][j] = '#';
                    /*for(int k = 0; k < 4; k++)
                        laser[k][i][j] = -1;
                    */
                    break;
                }
            }
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
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        int state = bfs.front().state;
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int ii = i;
            int jj = j;
            int nextstate = (state + k) % 4;
            while(1){
                ii += di[nextstate * 2];
                jj += dj[nextstate * 2];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    break;
                if(a[ii][jj] != '.')
                    break;
                cout << ii << " " << jj << " " << wall[nextstate] << " " << nextstate << "\n";
                laser[nextstate][ii][jj] = -1;
            }
            ii = i;
            jj = j;
            nextstate = (state + k) % 4;
            while(1){
                ii += di[nextstate * 2 + 1];
                jj += dj[nextstate * 2 + 1];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    break;
                if(a[ii][jj] != '.')
                    break;
                if(laser[nextstate][ii][jj])
                cout << ii << " " << jj << " " << wall[nextstate] << " " << nextstate << "\n";
                laser[nextstate][ii][jj] = -1;
            }
        }
    }
    dis[sti][stj] = 0;
    bfs.push({sti, stj, 0});
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        int state = bfs.front().state;
        bfs.pop();
        cout << i << " " << j << " " << state << "HAHA " << laser[state][i][j] << "\n";
        int nextstate = (state + 1) % 4;
        for(int k = 0; k < 4; k++){
            int ii = i + di4[k];
            int jj = j + dj4[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(laser[nextstate][ii][jj] == -1)
                continue;
            if(dis[ii][jj] <= dis[i][j] + 1)
                continue;
            dis[ii][jj] = dis[i][j] + 1;
            bfs.push({ii, jj, nextstate});
        }
    }
    cout << dis[eni][enj] << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while (q--){
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
2 3
S-#
.E.
1 5
S..E/
5 5
S....
.....
.-|..
.|-..
....E
*/
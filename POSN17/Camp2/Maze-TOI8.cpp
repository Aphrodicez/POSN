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

struct A{
    int i, j, bomb;
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

const int R = 2e2 + 10;
const int C = 2e2 + 10;

int a[R][C], disst[2][R][C], disen[2][R][C];

queue <A> bfs;

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void solve() {
    int r, c, sti, stj, eni, enj;
    cin >> r >> c;
    cin >> sti >> stj;
    cin >> eni >> enj;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){            
            cin >> a[i][j];
            for(int k = 0; k < 2; k++)
                disst[k][i][j] = disen[k][i][j] = 1e9;
        }
    }
    disst[0][sti][stj] = 0;
    bfs.push({sti, stj, 1});
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        int bomb = bfs.front().bomb;
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;        
            if(bomb && (disst[1][ii][jj] > disst[0][i][j] + 1) ){
                disst[1][ii][jj] = disst[0][i][j] + 1;
            }
            if(!a[ii][jj])
                continue;
            if(disst[1 - bomb][ii][jj] <= disst[1 - bomb][i][j] + 1)
                continue;            

            disst[1 - bomb][ii][jj] = disst[1 - bomb][i][j] + 1;
            bfs.push({ii, jj, bomb});
        }
    }
    disen[0][eni][enj] = 0;
    bfs.push({eni, enj, 1});
    while(!bfs.empty()){
        int i = bfs.front().i;
        int j = bfs.front().j;
        int bomb = bfs.front().bomb;

        bfs.pop();
        for(int k = 0; k < 4; k++){
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;         
            if(bomb && (disen[1][ii][jj] > disen[0][i][j] + 1) ){
                disen[1][ii][jj] = disen[0][i][j] + 1;
            }
            if(!a[ii][jj])
                continue;
            if(disen[1 - bomb][ii][jj] <= disen[1 - bomb][i][j] + 1)
                continue;
            disen[1 - bomb][ii][jj] = disen[1 - bomb][i][j] + 1;
            bfs.push({ii, jj, bomb});
        }
    }
    int ans = 2e9, cnt = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(disst[1][i][j] != 1e9 && disen[1][i][j] != 1e9){
                ans = min(ans, disst[1][i][j] + disen[1][i][j] + 1);
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << ans;
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
5 8
4 5
2 8
0 0 1 1 0 0 0 0
1 0 1 1 0 1 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1
*/
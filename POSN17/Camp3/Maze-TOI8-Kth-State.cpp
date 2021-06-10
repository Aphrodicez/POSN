/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search Kth State
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
    int i, j, usedbomb;
};

const int N = 2e2 + 10;
const int M = 2e5 + 10;

int a[N][N];

int disst[2][N][N], disen[2][N][N];

queue <GRAPH> bfs;

void solve() {
    memset(disst, -1, sizeof disst);
    memset(disen, -1, sizeof disen);
    int r, c, sti, stj, eni, enj;
    cin >> r >> c;
    cin >> sti >> stj;
    cin >> eni >> enj;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }
    disst[0][sti][stj] = 0;
    bfs.push({sti, stj, 0});
    while(!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        int usedbomb = bfs.front().usedbomb;
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int ii = i + d4i[k], jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == 0 && !usedbomb && disst[usedbomb + 1][ii][jj] == -1){
                disst[usedbomb+1][ii][jj] = disst[usedbomb][i][j] + 1;
                bfs.push({ii, jj, usedbomb + 1});
            }
            if(a[ii][jj] == 0)
                continue;
            if(disst[usedbomb][ii][jj] != -1)
                continue;
            disst[usedbomb][ii][jj] = disst[usedbomb][i][j] + 1;
            bfs.push({ii, jj, usedbomb});
        }
    }
    disen[0][eni][enj] = 0;
    bfs.push({eni, enj, 0});
    while(!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        int usedbomb = bfs.front().usedbomb;
        bfs.pop();
        for(int k = 0; k < 4; k++){
            int ii = i + d4i[k], jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == 0 && !usedbomb && disen[usedbomb + 1][ii][jj] == -1){
                disen[usedbomb+1][ii][jj] = disen[usedbomb][i][j] + 1;
                bfs.push({ii, jj, usedbomb + 1});
            }
            if(a[ii][jj] == 0)
                continue;
            if(disen[usedbomb][ii][jj] != -1)
                continue;
            disen[usedbomb][ii][jj] = disen[usedbomb][i][j] + 1;
            bfs.push({ii, jj, usedbomb});
        }
    }
    int cnt = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(a[i][j] == 0 && disst[1][i][j] != -1 && disen[1][i][j] != -1)
                cnt++;
        }
    }
    cout << cnt << '\n';
    cout << disst[1][eni][enj] + 1 << '\n';
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
5 8 
4 5 
2 8 
0 0 1 1 0 0 0 0 
1 0 1 1 0 1 1 1 
1 0 1 1 1 0 0 1 
1 1 0 0 1 0 0 1 
0 0 1 1 0 1 1 1 

6 8 
1 4 
2 7 
0 0 1 1 0 0 0 0 
1 0 1 1 0 0 1 1 
1 0 1 1 1 0 0 1 
1 1 0 0 1 0 0 1 
0 0 1 1 0 1 1 1 
0 1 0 1 1 1 1 1

5 8 
1 4 
2 1 
0 0 1 1 0 0 0 0 
1 0 1 1 0 0 1 1 
1 0 1 1 1 0 0 1 
1 1 0 0 1 0 0 1 
0 1 1 1 0 1 1 1
*/
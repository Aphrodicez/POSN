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

const int N = 2e2 + 10;
const int M = 2e5 + 10;

int a[N][N], disst[N][N], disen[N][N];

queue <GRAPH> bfs;

void solve() {
    int r, c, sti, stj, eni, enj;
    cin >> r >> c;
    cin >> sti >> stj;
    cin >> eni >> enj;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    memset(disst, -1, sizeof disst);
    disst[sti][stj] = 0;
    bfs.push({sti, stj});
    while(!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(disst[ii][jj] != -1)
                continue;
            if(!a[ii][jj]){
                disst[ii][jj] = disst[i][j] + 1;
                continue;
            }
            disst[ii][jj] = disst[i][j] + 1;
            bfs.push({ii, jj});
        }
    }
    memset(disen, -1, sizeof disen);
    disen[eni][enj] = 0;
    bfs.push({eni, enj});
    while(!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(disen[ii][jj] != -1)
                continue;
            if(!a[ii][jj]){
                disen[ii][jj] = disen[i][j] + 1;
                continue;
            }
            disen[ii][jj] = disen[i][j] + 1;
            bfs.push({ii, jj});
        }
    }
    int ans = 2e9, cnt = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(!a[i][j] && disst[i][j] != -1 && disen[i][j] != -1) {
                cnt++;
                ans = min(ans, disst[i][j] + disen[i][j] + 1);
            }
        }
    }
    cout << cnt << '\n';
    cout << ans << '\n';
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
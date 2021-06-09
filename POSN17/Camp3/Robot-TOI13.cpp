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

const int N = 2e3 + 10;
const int M = 2e5 + 10;

char a[N][N];

int dis[N][N];

queue <GRAPH> bfs;

void solve() {
    memset(dis, -1, sizeof dis);
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
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
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == 'W')
                continue;
            if(dis[ii][jj] != -1)
                continue;
            dis[ii][jj] = dis[i][j] + 1;
            bfs.push({ii, jj});
        }
    }
    int ans = 0, cnt = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(a[i][j] == 'A' && dis[i][j] != -1){
                cnt++;
                ans += dis[i][j] * 2;
            }
        }
    }
    cout << cnt << " " << ans << '\n';
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

5 5
WEEEE
AWAEW
WEEWW
WEEXE
WWEEE
*/
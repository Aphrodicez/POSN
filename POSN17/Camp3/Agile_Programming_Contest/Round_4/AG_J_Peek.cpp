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
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_bfseue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    int i, j, state, dir;
};

const int N = 3e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int di[] = {-1, 1, 0, 0, -1, 1, -1, 1}, dj[] = {0, 0, -1, 1, -1, 1, 1, -1};

int mp[10][10];

char a[310][310];

int r, c, q;

queue <GRAPH> bfs;

int dis[4][310][310];

/*
| - \ /
*/

void BFS(int sti, int stj, int cnt) {
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            for(int k = 0; k < 4; k++){
                dis[k][i][j] = 2e9;
            }
        }
    }
    for(int k = 0; k < 4; k++)
        dis[k][sti][stj] = 0;
    for(int k = 0; k < 8; k++){
        bfs.push({sti, stj, k / 2, k});
    }
    while (!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        int nowstate = bfs.front().state;
        int nowdir = bfs.front().dir;
        bfs.pop();
        if(a[i][j] == 'X'){
            cnt--;
            a[i][j] = '.';
            if(cnt == 0)
                return;
        }
        int lasti = i, lastj = j;
        while (1){            
            int ii = lasti + di[nowdir], jj = lastj + dj[nowdir];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                break;
            if(a[ii][jj] == '#')
                break;
            if(dis[nowstate][ii][jj] < dis[nowstate][i][j] + 1)
                break;
            lasti = ii, lastj = jj;
            dis[nowstate][ii][jj] = dis[nowstate][i][j];
            for(int k = 0; k < 2; k++){
                int nextdir = mp[nowdir][k];
                int nextstate = nextdir / 2;
                if(dis[nextstate][ii][jj] < dis[nowstate][i][j] + 1)
                    continue;
                dis[nextstate][ii][jj] = dis[nowstate][i][j] + 1;
                bfs.push({ii, jj, nextstate, nextdir});
            }
        }
    }
}

void solve() {
    int sti, stj, cnt = 0;
    cin >> r >> c >> q;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J')
                sti = i, stj = j;
            if(a[i][j] == 'X')
                cnt++;
        }
    }
    for(int k = 0; k < 2; k++)
        mp[0][k] = mp[1][1 - k] = k + 2; /// vert
    for(int k = 0; k < 2; k++)
        mp[2][k] = mp[3][1 - k] = k; /// horiz
    for(int k = 0; k < 2; k++)
        mp[4][k] = mp[5][1 - k] = 4 + k + 2;
    for(int k = 0; k < 2; k++)
        mp[6][k] = mp[7][1 - k] = 4 + k;
    BFS(sti, stj, cnt);
    while(q--){
        int ans = 2e9;
        int eni, enj;
        cin >> eni >> enj;
        for(int k = 0; k < 4; k++){
            ans = min(ans, dis[k][eni][enj]);
        }
        if(ans == 2e9)
            ans = -1;
        cout << ans << "\n";
    }
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
4 10 1
..........
##########
...X..#..J
.......#.#
3 4

4 10 1
..........
##########
...X...#.J
.......#.#
3 4

4 10 1
#.X.......
.#.#.#.#..
..#.#.#.#J
...#.#.#.#
1 3
*/
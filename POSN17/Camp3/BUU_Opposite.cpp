/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: All Pair Shortest Path + Breadth First Search
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

struct BFS {
    int i, j;
};

struct VALID {
    int ai, aj, bi, bj, w;
};

const int N = 3e1 + 10;
const int M = 2e5 + 10;

char a[N][N];

int dis[N][N][N][N], isValid[N][N][N][N];

queue <BFS> bfs;

queue <VALID> valid;

int r, c;

void genShortestPath(int sti, int stj){
    dis[sti][stj][sti][stj] = 0;
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
            if(a[ii][jj] == '#')
                continue;
            if(dis[sti][stj][ii][jj] != -1)
                continue;
            dis[sti][stj][ii][jj] = dis[sti][stj][i][j] + 1;
            bfs.push({ii, jj});
        }
    }
}

bool validMove(int ii, int jj){
    if(ii < 1 || jj < 1 || ii > r || jj > c)
        return false;
    if(a[ii][jj] == '#')
        return false;
    return true;
}

void solve() {
    memset(isValid, 0, sizeof isValid);
    memset(dis, -1, sizeof dis);
    int sti, stj, eni, enj;
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A')
                sti = i, stj = j;
            if(a[i][j] == 'B')
                eni = i, enj = j;
        }
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            genShortestPath(i, j);
        }
    }
    if(dis[sti][stj][eni][enj] == -1) {
        cout << -1 << " " << 0 << '\n';
        return ;
    }
    int mn = dis[sti][stj][eni][enj];
    int walk = 0;
    isValid[sti][stj][eni][enj] = 1;
    valid.push({sti, stj, eni, enj, 0});
    while(!valid.empty()) {
        int ai = valid.front().ai;
        int aj = valid.front().aj;
        int bi = valid.front().bi;
        int bj = valid.front().bj;
        int w = valid.front().w;
        valid.pop();
        if(mn > dis[ai][aj][bi][bj]) {
            mn = dis[ai][aj][bi][bj];
            walk = w;
        }
        for(int k = 0; k < 4; k++) {
            int nai = ai + d4i[k], naj = aj + d4j[k];
            int nbi = bi + d4i[k] * -1, nbj = bj + d4j[k] * -1;
            if(!validMove(nai, naj))
                nai = ai, naj = aj;
            if(!validMove(nbi, nbj))
                nbi = bi, nbj = bj;
            if(isValid[nai][naj][nbi][nbj])
                continue;
            isValid[nai][naj][nbi][nbj] = 1;
            valid.push({nai, naj, nbi, nbj, w + 1});
        }
    }
    cout << mn << " " << walk << '\n';
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4
2 5
A....
....B
1 5
A.#.B
1 5
A...B
3 5
A....
###..
###.B
*/
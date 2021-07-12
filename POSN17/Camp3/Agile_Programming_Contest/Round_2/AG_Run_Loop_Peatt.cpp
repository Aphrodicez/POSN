/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search + Greedy Algorithm
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

const int N = 1e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

char a[N][N];

int dis[N][N];

/// D L R U

const int di[] = {1, 0, 0, -1};
const int dj[] = {0, -1, 1, 0};

char alpha[] = {'D', 'L', 'R', 'U'};

queue <GRAPH> bfs;

vector <int> ans;

void solve() {
    while(!bfs.empty())
        bfs.pop();
    ans.clear();
    int r, c, remainingWalk;
    cin >> r >> c >> remainingWalk;
    int sti, stj;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dis[i][j] = 1e6 + 10;
            cin >> a[i][j];
            if(a[i][j] == 'P')
                sti = i, stj = j;
        }
    }
    if(remainingWalk % 2) {
        cout << "Can't do" << "\n";
        return ;
    }
    dis[sti][stj] = 0;
    bfs.push({sti, stj});
    while(!bfs.empty()) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(dis[ii][jj] <= dis[i][j] + 1)
                continue;
            dis[ii][jj] = dis[i][j] + 1;
            if(dis[ii][jj] * 2 >= remainingWalk)
                continue;
            bfs.push({ii, jj});
        }
    }
    bfs.push({sti, stj});
    while(!bfs.empty() && remainingWalk > 0) {
        int i = bfs.front().i;
        int j = bfs.front().j;
        remainingWalk--;
        bfs.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(dis[ii][jj] > remainingWalk)
                continue;
            ans.push_back(alpha[k]);
            bfs.push({ii, jj});
            break;
        }
    }
    if(remainingWalk) {
        cout << "Can't do" << "\n";
        return ;
    }
    for(char x : ans)
        cout << x;
    cout << "\n";
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
2
3 5 4
##...
...P#
...#.
2 2 4
P#
#.
*/
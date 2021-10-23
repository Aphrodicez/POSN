/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    int i, j;
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

char a[40][40];

queue <GRAPH> qu;

int r, c;

bool isWarp = false;
int ans = 0;

void bfs(int sti, int stj) {
    a[sti][stj] = '#';
    qu.push({sti, stj});
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        qu.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + di[k];
            int jj = j + dj[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(a[ii][jj] == '#')
                continue;
            if(a[ii][jj] == '*') {
                ans++;
            }
            if(a[ii][jj] == 'W') {
                isWarp = true;
            }
            a[ii][jj] = '#';
            qu.push({ii, jj});
        }
    }
}

void solve() {
    isWarp = false;
    ans = 0;
    scanf("%d %d", &r, &c);
    int sti, stj;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf(" %c", &a[i][j]);
            if(a[i][j] == 'A') {
                sti = i, stj = j;
            }
        }
    }
    bfs(sti, stj);
    if(isWarp) {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(a[i][j] == 'W') {
                    bfs(i, j);
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    setIO();
    int q = 1;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
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
A*.#...
..#..*#
.*####.
##..#..
.#.*#..
5 7
A*.#...
.W#..*#
.*####.
##WW#.W
W#.*#..
*/
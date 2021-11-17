/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Maximum Square in Grid ] + Breadth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 7e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

const int d2i[] = {-1, 0};
const int d2j[] = {0, -1};

struct BFS {
    int i, j;
};

int r, c;

char a[MaxN][MaxN];

int dp[MaxN][MaxN];
int river[MaxN][MaxN];
bool counted[MaxN * MaxN];

queue <BFS> qu;

void bfs(int sti, int stj, int cnt) {
    while(!qu.empty())
        qu.pop();
    river[sti][stj] = cnt;
    qu.push({sti, stj});
    while(!qu.empty()) {
        int i = qu.front().i;
        int j = qu.front().j;
        qu.pop();
        for(int k = 0; k < 4; k++) {
            int ii = i + d4i[k];
            int jj = j + d4j[k];
            if(ii < 1 || jj < 1 || ii > r || jj > c)
                continue;
            if(river[ii][jj] != -1)
                continue;
            river[ii][jj] = cnt;
            qu.push({ii, jj});
        }
    }
}

int check_river(int eni, int enj, int sz) {
    memset(counted, false, sizeof (counted));
    int cnt = 0;
    for(int i = eni - sz + 1; i <= eni; i++) {
        for(int j = enj - sz + 1; j <= enj; j++) {
            if(river[i][j] && !counted[river[i][j]]) {
                cnt++;
                counted[river[i][j]]++;
            }
        }
    }
    return cnt;
}

void solve() {
    scanf("%d %d", &c, &r);
    int mx = 0;
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
        for(int j = 1; j <= c; j++) {
            if(a[i][j] == 'T') {
                dp[i][j] = 0;
                continue;
            }
            if(a[i][j] == 'P') {
                river[i][j] = -1;
            }
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            mx = max(mx, dp[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(river[i][j] == -1) {
                bfs(i, j, ++cnt);
            }
        }
    }
    int mn = r * c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(dp[i][j] == mx) {
                mn = min(mn, check_river(i, j, mx));
            }
        }
    }
    printf("%d %d\n", mx * mx, mn);
}

int main() {
    int q = 1;
    
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
8 6
SSSSSSSS
SSSSSSSS
SPPSSSSS
SSSPSSSS
SSSSSTTS
PSSSSTSS

6 5
TSSSSS
TTSSSS
SSSPSS
SSPPPS
TSSPST

2 2
TT
TT

11 5
SSSSSTSSSSS
SSPSSTSSPSS
SPPPSTSSSSS
SSPSSTSSPSS
SSSSSTSSSSS
*/
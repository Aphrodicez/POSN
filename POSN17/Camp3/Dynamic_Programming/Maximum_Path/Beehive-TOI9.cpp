/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Maximum Path]
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
    
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

int dp[N][N], path[N][N];

void solve() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int j = 1; j <= c; j++) {
        path[1][j] = 1;
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &dp[i][j]);
            int cnt = 0, mx = 0;
            for(int k = 0; k < 2; k++) {
                int ii = i - 1;
                int jj = j + k - (i % 2);
                if(jj < 1 || jj > c)
                    continue;
                if(dp[ii][jj] == mx)
                    cnt += path[ii][jj];
                if(dp[ii][jj] > mx){
                    cnt = path[ii][jj];
                    mx = dp[ii][jj];
                }
            }
            dp[i][j] += mx;
            path[i][j] += cnt;
        }
    }
    int cnt = 0, mx = 0;
    for(int j = 1; j <= c; j++) {
        if(dp[r][j] == mx)
            cnt += path[r][j];
        if(dp[r][j] > mx) {
            cnt = path[r][j];
            mx = dp[r][j];
        }
    }
    printf("%d %d\n", mx, cnt);
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
5 4
8 10 25 3
4 12 33 1
4 51 13 4
1 20 11 12
1 5 6 25

4 3
0 10 10
0 14 0
0 17 17
0 20 0

7 5
10 8 25 13 16
4 23 12 1 14
14 17 0 11 26
6 3 3 8 10
4 5 16 5 14
8 4 4 1 7
8 3 1 4 5
*/
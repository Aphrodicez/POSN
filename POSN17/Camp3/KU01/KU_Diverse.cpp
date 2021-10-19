/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Quicksum 2D ]
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

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int MaxN = 6e1 + 10;
const int MaxM = 2e5 + 10;

int dp[10][60][60];

void TESTCASE() {
    
}

void solve() {
    memset(dp, 0, sizeof dp);
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            int num;
            scanf("%d", &num);
            dp[num][i][j]++;
            for(int k = 0; k <= 9; k++) {
                dp[k][i][j] += dp[k][i - 1][j] + dp[k][i][j - 1] - dp[k][i - 1][j - 1];
            }
        }
    }
    int ans = 0;
    for(int i = 5; i <= r; i++) {
        for(int j = 5; j <= c; j++) {
            int cnt = 0;
            for(int k = 0; k <= 9; k++) {
                if(dp[k][i][j] - dp[k][i - 5][j] - dp[k][i][j - 5] + dp[k][i - 5][j - 5] > 0) {
                    cnt++;
                }
            }
            if(cnt >= 5) {
                ans++;
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
3
6 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
6 6
0 0 0 0 0 0
0 1 1 1 0 0
0 1 1 0 3 0
0 1 0 4 3 0
0 3 3 3 3 0
0 0 0 0 0 2
10 12
0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 5 0 0 0
0 0 0 3 0 0 0 0 6 0 0 0
0 0 0 0 3 0 0 0 0 0 0 0
0 0 0 0 3 9 0 9 9 9 9 9
0 0 0 0 0 0 0 9 9 9 9 9
0 0 0 0 0 0 0 9 9 9 9 9
0 0 0 0 0 0 0 9 9 9 9 9
0 0 0 0 0 0 0 9 9 9 9 9
*/
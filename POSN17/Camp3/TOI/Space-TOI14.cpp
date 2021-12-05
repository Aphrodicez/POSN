/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force Algorithm + Dynamic Programming + Math
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

const int MaxN = 2e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char a[2][MaxN];
int dp[2][MaxN], h[2][MaxN], w[2][MaxN];

int c, r;
int ans_sq = 0, ans_diamond = 0, ans_tri = 0;

void check(int i) {
    int cnt = 0;
    for(int j = 1; j <= c; j++) {
        cnt += a[i % 2][j] - '0';
        dp[i % 2][j] = h[i % 2][j] = w[i % 2][j] = 0;
        if(a[i % 2][j] != '1' && a[i % 2][j - 1] != '1' && a[i % 2][j + 1] != '1' && a[1 - i % 2][j + 1] != '1' && dp[1 - i % 2][j]) {
            int sum = dp[1 - i % 2][j];
            if(sum == h[1 - i % 2][j] * w[1 - i % 2][j]) {
                ans_sq++;
            }
            else if(h[1 - i % 2][j] == w[1 - i % 2][j]) {
                ans_diamond++;
            }
            else {
                ans_tri++;
            }
        }
        if(a[i % 2][j] != '1')
            continue;
        if(a[i % 2][j + 1] != '1') {
            int sz = cnt;
            cnt = 0;
            int rb = j;
            int lb = rb - sz + 1;
            int mxsum = 0, mxh = 0, mxsz = sz;
            for(int k = lb; k <= rb; k++) {
                mxsum = max(mxsum, dp[1 - i % 2][k]);
                mxh = max(mxh, h[1 - i % 2][k]);
                mxsz = max(mxsz, w[1 - i % 2][k]);
            }
            for(int k = lb; k <= rb; k++) {
                dp[i % 2][k] = mxsum + sz;
                h[i % 2][k] = mxh + 1;
                w[i % 2][k] = mxsz;
            }
        }
    }
}

void solve() {
    scanf("%d %d", &c, &r);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i % 2] + 1);
        check(i);
    }
    int i = r + 1;
    for(int j = 1; j <= c; j++)
        a[i % 2][j] = '0';
    check(i);
    printf("%d %d %d\n", ans_sq, ans_diamond, ans_tri);
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
20 12
00000000000000000000
00100000001111111110
01110000000111111100
11111000000011111000
00000000000001110000
00000000000000100000
00000000000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000

20 12
00000000000000000000
10000000001111111110
11000100000111111100
11101110000011111000
11000000000001110000
10000000000000100000
00000000000000000000
11111000000000100000
11111000000001110000
11111000000011111000
11111000000001110000
11111000000000100000

20 12
00000000000000000000
10000000001111111110
11000100000111111100
11101110000011111000
11000000000001110000
10000000000000100000
00000000000000000110
00011111000001000110
00011111000011100000
00011111000111110111
00011111000011100111
00011111000001000111
*/
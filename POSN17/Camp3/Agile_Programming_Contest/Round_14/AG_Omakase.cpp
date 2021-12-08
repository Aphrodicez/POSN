/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Divide and Conquer
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

const int MaxN = 3e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN][MaxN];
int cnt[MaxN * MaxN], all[MaxN * MaxN];

int dp[MaxN][MaxN][MaxN][MaxN];

int divide(int li, int lj, int ri, int rj) {
    if(dp[li][lj][ri][rj] != -1)
        return dp[li][lj][ri][rj];
    dp[li][lj][ri][rj] = 0;
    if(li == ri || lj == rj) {
        memset(cnt, 0, sizeof (cnt));
        for(int i = li; i <= ri; i++) {
            for(int j = lj; j <= rj; j++) {
                if(++cnt[a[i][j]] == all[a[i][j]]) {
                    dp[li][lj][ri][rj]++;
                }
            }
        }
        return dp[li][lj][ri][rj];
    }
    dp[li][lj][ri][rj] = max(dp[li][lj][ri][rj], divide(li, lj, li, rj) + divide(li + 1, lj, ri, rj));
    dp[li][lj][ri][rj] = max(dp[li][lj][ri][rj], divide(li, lj, ri - 1, rj) + divide(ri, lj, ri, rj));
    dp[li][lj][ri][rj] = max(dp[li][lj][ri][rj], divide(li, lj, ri, lj) + divide(li, lj + 1, ri, rj));
    dp[li][lj][ri][rj] = max(dp[li][lj][ri][rj], divide(li, lj, ri, rj - 1) + divide(li, rj, ri, rj));
    return dp[li][lj][ri][rj];
}

int r, c;

void solve() {
    memset(all, 0, sizeof (all));
    memset(dp, -1, sizeof (dp));
    int m;
    scanf("%d %d %d", &r, &c, &m);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
            all[a[i][j]]++;
        }
    }
    divide(1, 1, r, c);
    printf("%d\n", dp[1][1][r][c]);
}

int main() {
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
1
4 6 11
1 6 5 8 9 10
1 7 5 7 11 11
1 2 5 7 4 4
2 6 3 3 3 3
*/
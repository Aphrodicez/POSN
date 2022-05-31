/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming [ Range Update 2D ] + Constructive Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e3 + 10;

char a[MaxN][MaxN];
int dp[MaxN][MaxN];

int li[MaxN][MaxN], ri[MaxN][MaxN];
int lj[MaxN][MaxN], rj[MaxN][MaxN];

void solve() {
    memset(dp, 0, sizeof (dp));
    int R, C;
    scanf("%d %d", &R, &C);
    for(int i = 1; i <= R; i++) {
        scanf(" %s", a[i] + 1);
    }
    for(int i = 1; i <= R; i++) {
        lj[i][0] = 0;
        for(int j = 1; j <= C; j++) {
            lj[i][j] = lj[i][j - 1];
            if(a[i][j] == '#')
                lj[i][j] = j;
        }
        rj[i][C + 1] = C + 1;
        for(int j = C; j >= 1; j--) {
            rj[i][j] = rj[i][j + 1];
            if(a[i][j] == '#')
                rj[i][j] = j;
        }
    }
    for(int j = 1; j <= C; j++) {
        li[0][j] = 0;
        for(int i = 1; i <= R; i++) {
            li[i][j] = li[i - 1][j];
            if(a[i][j] == '#')
                li[i][j] = i;
        }
        ri[R + 1][j] = R + 1;
        for(int i = R; i >= 1; i--) {
            ri[i][j] = ri[i + 1][j];
            if(a[i][j] == '#')
                ri[i][j] = i;
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int i, j, w;
        scanf("%d %d %d", &i, &j, &w);
        if(a[i][j] == '#')
            continue;
        int l, r; 
        l = max(lj[i][j] + 1, j - w);
        r = min(rj[i][j] - 1, j + w);
        dp[i][l]++;
        dp[i + 1][l]--;
        dp[i][r + 1]--;
        dp[i + 1][r + 1]++;
        ///
        l = max(li[i][j] + 1, i - w);
        r = min(ri[i][j] - 1, i + w);
        dp[l][j]++;
        dp[l][j + 1]--;
        dp[r + 1][j]--;
        dp[r + 1][j + 1]++;
        ///
        dp[i][j]++;
        dp[i][j + 1]--;
        dp[i + 1][j]--;
        dp[i + 1][j + 1]++;
    }
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if(a[i][j] == '.' && dp[i][j] & 1)
                a[i][j] = '*';
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int q = 1;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/*
2
7 7 
.......
.......
.......
.......
.......
.......
.......
2
4 4 2
2 3 3
7 7 
.......
...#...
.......
..#....
.......
.......
.......
3
4 4 2
2 3 3
2 4 1
*/
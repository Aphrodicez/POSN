/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Constructive Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 5e2 + 10;

char a[MaxN][MaxN];

int dp[MaxN][MaxN];

int r, c;

void update(int i) {
    int last;
    for(int j = 1; j <= c; j++) {
        dp[i][j] = MaxN;
    }
    last = 0;
    for(int j = 1; j <= c; j++) {
        if(a[i][j] == 'x')
            last = j;
        if(last)
            dp[i][j] = min(dp[i][j], abs(j - last));
    }
    last = 0;
    for(int j = c; j >= 1; j--) {
        if(a[i][j] == 'x')
            last = j;
        if(last)
            dp[i][j] = min(dp[i][j], abs(j - last));
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
    }
    for(int i = 1; i <= r; i++) {
        update(i);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int sti, stj;
        scanf("%d %d", &sti, &stj);
        int ans = 2e9;
        for(int i = 1; i <= r; i++) {
            ans = min(ans, (i - sti) * (i - sti) + dp[i][stj] * dp[i][stj]);
        }
        a[sti][stj] = 'x';
        update(sti);
        printf("%d\n", ans);
    }
    return 0;
}

/*
5 5
..x..
....x
.....
.....
.....
4
3 1
5 3
2 5
4 5
*/
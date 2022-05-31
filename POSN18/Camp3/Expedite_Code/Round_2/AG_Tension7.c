/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Matrix Chain Multiplication + Prefix Sum
    Status	: Accepted
*/

#include <stdio.h>

const int MaxN = 6e2 + 10;

int qs[MaxN];
int dp[MaxN][MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &qs[i]);
            qs[i] += qs[i - 1];
        }
        for(int i = 1; i <= n; i++)
            dp[i][i] = 0;
        for(int sz = 2; sz <= n; sz++) {
            for(int l = 1; l + sz - 1 <= n; l++) {
                int r = l + sz - 1;
                dp[l][r] = 0;
                for(int mid = l; mid <= r - 1; mid++) {
                    int mn = qs[mid] - qs[l - 1];
                    int mx = qs[r] - qs[mid];
                    if(mn > mx) {
                        int tmp = mn;
                        mn = mx;
                        mx = tmp;
                    }
                    if(dp[l][r] < dp[l][mid] + dp[mid + 1][r] + 2 * mn + mx)
                        dp[l][r] = dp[l][mid] + dp[mid + 1][r] + 2 * mn + mx;
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}

/*
3
4
1 4 5 2
4
1 2 3 5
3
99 9 9
*/
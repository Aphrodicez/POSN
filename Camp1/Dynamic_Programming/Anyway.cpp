/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
*/

#include <stdio.h>

int dp[1010][1010];

int main() {
    dp[1][1] = 1;
    int r, c, k;
    scanf("%d %d %d", &c, &r, &k);
    r++, c++;
    while(k--) {
        int i, j;
        scanf("%d %d", &j, &i);
        i++, j++;
        dp[i][j] = -1;
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }            
            if(i == 1 && j == 1)
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
        }
    }
    printf("%d\n", dp[r][c]);
    return 0;
}

/*
3 2 2
3 1
3 0
*/
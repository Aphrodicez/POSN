/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming [ Minimum Path ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &dp[i][j]);
        }
    }
    for(int i = 0; i <= r + 1; i++)
        dp[i][0] = dp[i][c + 1] = 1e9;
    for(int j = 0; j <= c + 1; j++)
        dp[0][j] = dp[r + 1][j] = 1e9;
    
    for(int i = r - 1; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            dp[i][j] = min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]}) + dp[i][j];
        }
    }
    int ans = 1e9;
    for(int j = 1; j <= c; j++)
        ans = min(ans, dp[1][j]);
    printf("%d\n", ans);
    return 0;
}

/*
5 6
3 6 1 7 2 3
4 7 9 5 2 1
3 3 3 9 9 8
7 5 7 5 8 9
2 4 1 3 7 1
*/
/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming [ Ad-Hoc ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e3 + 10;

int a[MaxN];

int dp[MaxN][MaxN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - a[i]);
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1] + a[i], dp[i - 1][j + 2] - a[i]);
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}

/*
7
1 2 3 4 5 6 7

9
5 5 5 5 5 5 5 5 100
*/
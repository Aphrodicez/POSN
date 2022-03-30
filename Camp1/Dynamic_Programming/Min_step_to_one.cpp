/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1000010];

int main() {
    /// Precompute
    dp[1] = 0;
    for(int i = 2; i <= 1000000; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if(i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int p;
        scanf("%d", &p);
        printf("%d\n", dp[p]);
    }
    return 0;
}

/*
2
4
7
*/
/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming [ Ad-Hoc ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 10;

long long t[2][MaxN];
long long dp[MaxN];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &t[0][i]);
        t[1][i] = t[1][i - 1] + t[0][i] / 2;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        long long m;
        scanf("%lld", &m);
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + t[0][i];
            if(i >= k + 1)
                dp[i] = min(dp[i], m + dp[i - k] + t[1][i] - t[1][i - k]);
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}

/*
7 2
10 8 2 4 16 6 12
2
5 
100
*/
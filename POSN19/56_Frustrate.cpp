#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

int a[MaxN];
int dp[MaxN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] = dp[i - 1] + a[i];
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", dp[r] - dp[l - 1]);
    }
    return 0;
}

/*
5
2 5 1 7 3
2
1 3
2 5
*/
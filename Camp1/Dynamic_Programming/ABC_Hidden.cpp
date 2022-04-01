/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

char s[1000010];
long long dp[4];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        memset(dp, 0, sizeof(dp));
        scanf(" %s", s);
        int len = strlen(s);
        dp[0] = 1;
        for(int i = 0; i < len; i++) {
            dp[s[i] - 'A' + 1] += dp[s[i] - 'A'];
        }
        printf("%lld\n", dp[3]);
    }
    return 0;
}

/*
1
ABC

3
AABC
ABAABBCC
AB
*/
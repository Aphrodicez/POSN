/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Matrix Exponentation [ Binary Lifting ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct MATRIX {
    long long arr[2][2];
};

MATRIX operator* (MATRIX &a, MATRIX &b) {
    MATRIX tmp;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            tmp.arr[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                tmp.arr[i][j] += (a.arr[i][k] * b.arr[k][j]) % MOD;
                tmp.arr[i][j] %= MOD;
            }
        }
    }
    return tmp;
}

MATRIX dp[70];
MATRIX dp0 = {{{1, 0}, {1, 0}}};

long long nth_fibonacci(long long n) {
    MATRIX ans = dp0;
    for(int k = 0; k <= 63; k++) {
        if(n & (1ll << k))
            ans = dp[k] * ans;
    }
    return ans.arr[0][0];
}

int main() {
    dp[0] = {{{1, 1}, {1, 0}}};
    for(int k = 1; k <= 63; k++) {
        dp[k] = dp[k - 1] * dp[k - 1];
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        long long sumr = 3ll * nth_fibonacci(r + 2);
        long long suml = 3ll * nth_fibonacci(l - 1 + 2);
        printf("%lld\n", (((sumr - suml) % MOD) + MOD) % MOD);
    }
    return 0;
}

/*
3
1 1
2 3
1 4
*/
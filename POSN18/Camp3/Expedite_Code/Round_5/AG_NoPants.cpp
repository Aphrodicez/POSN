/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Matrix Exponentiation [ Binary Lifting ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 250 + 10;

struct MATRIX {
    double arr[MaxN][MaxN];
};

int n;

MATRIX operator* (MATRIX &a, MATRIX &b) {
    MATRIX tmp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp.arr[i][j] = 0;
            for(int k = 0; k < n; k++) {
                tmp.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }
    return tmp;
}

MATRIX ans;

MATRIX dp[30];

int main() {
    int t;
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &ans.arr[i][0]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%lf", &dp[0].arr[j][i]);
        }
    }
    for(int k = 1; k <= 20; k++) {
        dp[k] = dp[k - 1] * dp[k - 1];
    }
    for(int k = 0; k <= 20; k++) {
        if(t & (1 << k))
            ans = dp[k] * ans;
    }
    for(int i = 0; i < n; i++) {
        printf("%.2lf\n", ans.arr[i][0]);
    }
    return 0;
}

/*
3 1
30 40 50
0.5 0.2 0.3
0.1 0.4 0.5
0.3 0.3 0.4
*/
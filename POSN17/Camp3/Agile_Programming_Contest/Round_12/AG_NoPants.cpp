
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Exponentation
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 25e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int n;

struct MATRIX {
    double a[MaxN][MaxN];
    void init() {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                a[i][j] = 0;
            }
        }
    }
};

MATRIX operator* (const MATRIX &a, const MATRIX &b) {
    MATRIX tmp;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            tmp.a[i][j] = 0;
            for(int k = 1; k <= n; k++) {
                tmp.a[i][j] += a.a[i][k] * b.a[k][j];
            }
        }
    }
    return tmp;
}

MATRIX dp[30];
MATRIX base;

void solve() {
    int t;
    scanf("%d %d", &n, &t);
    base.init();
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &base.a[i][1]);
    }
    MATRIX tmp;
    tmp.init();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            tmp.a[i][j] = 0;
            scanf("%lf", &dp[0].a[j][i]);
        }
        tmp.a[i][i] = 1;
    }
    for(int k = 1; k <= 20; k++) {
        dp[k] = dp[k - 1] * dp[k - 1];
    }
    for(int i = 0; t; i++) {
        if(t & 1) {
            tmp = tmp * dp[i];
        }
        t >>= 1;
    }
    MATRIX ans = tmp * base;
    for(int i = 1; i <= n; i++) {
        printf("%.2lf\n", ans.a[i][1]);
    }
    return;
}

int main() {
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
3 1
30 40 50
0.5 0.2 0.3
0.1 0.4 0.5
0.3 0.3 0.4
*/
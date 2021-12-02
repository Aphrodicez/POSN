/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming + Math
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

const int MaxN = 1e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

long long mod(long long val) {
    return ((val % MOD) + MOD) % MOD;
}

long long dp[MaxN], qs[MaxN], all[MaxN];

void solve() {
    int n;
    long long m;
    int k;
    scanf("%d %lld %d", &n, &m, &k);
    all[0] = 1;
    for(int i = 1; i <= k - 1; i++) {
        all[i] = mod(all[i - 1] * m);
        dp[i] = all[i];
        qs[i] = mod(qs[i - 1] + dp[i]);
    }
    for(int i = k; i <= n; i++) {
        dp[i] = mod(mod(m - 1) * mod(qs[i - 1] - qs[max(i - k, 0)]));
        all[i] = mod(all[i - 1] * m);
        qs[i] = mod(qs[i - 1] + dp[i]);
    }
    printf("%lld\n", mod(all[n] - dp[n]));
}

int main() {
    int q = 1;
    scanf("%d", &q);
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
1
3 2 2
*/
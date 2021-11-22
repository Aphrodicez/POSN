/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Ad - Hoc ]
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

const int MaxN = 5e4 + 10;
const int MaxK = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

long long qs[MaxN];
long long dp[2][MaxN], mn[2][MaxN];

void solve() {
    memset(mn, 127, sizeof (mn));
    memset(dp, 127, sizeof (dp));
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    mn[0][0] = -qs[0];

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &qs[i]);
        qs[i] += qs[i - 1];
        mn[0][i] = min(mn[0][i - 1], -qs[i]);
    }
    for(int state = 1; state <= k; state++) {
        memset(dp[state & 1], 127, sizeof (dp[state & 1]));
        memset(mn[state & 1], 127, sizeof (mn[state & 1]));
        for(int i = m; i <= n; i++) {
            dp[state & 1][i] = min(dp[state & 1][i - 1], qs[i] + mn[state & 1 ^ 1][i - m]);
            mn[state & 1][i] = min(mn[state & 1][i - 1], dp[state & 1][i - 1] - qs[i]);
        }
    }
    printf("%lld\n", qs[n] - dp[k & 1][n]);
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
2
7 1 3 
1 0 4 8 5 7 6
12 3 2 
2 -8 3 -4 5 -7 3 5 -2 2 4 1
*/
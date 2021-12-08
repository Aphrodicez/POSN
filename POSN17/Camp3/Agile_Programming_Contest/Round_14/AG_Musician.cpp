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

const int MaxN = 3e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];
int dp[MaxN][MaxN];

void solve() {
    memset(dp, 0, sizeof (dp));
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= k - 1; i++) {
        dp[i][0] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i < k)
            dp[i][0] = a[i];
        for(int j = max(1, i - k + 1); j <= i - 1; j++) {
            dp[i][j] = dp[j][max(0, i - k)] + a[i];
        }
        for(int j = i - 2; j >= max(0, i - k + 1); j--) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    int ans = 1e9;
    for(int i = n - k + 2; i <= n; i++) {
        ans = min(ans, dp[i][n - k + 1]);
    }
    printf("%d\n", ans);
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
6 3
1 100 1 1 100 1
6 4
1 100 1 1 100 1
*/
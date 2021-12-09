/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];
int l[MaxN], r[MaxN];
int dp[MaxN];

void solve() {
    memset(dp, 0, sizeof dp);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    l[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] <= a[i - 1]) {
            l[i] = 1;
            continue;
        }
        l[i] = l[i - 1] + 1;
    }
    r[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] >= a[i + 1]) {
            r[i] = 1;
            continue;
        }
        r[i] = r[i + 1] + 1;
    }
    int ans = 0;
    int sz = 0;
    for(int i = 1; i <= n; i++) {
        int lb = lower_bound(dp, dp + sz, a[i]) - (dp + 1);
        lb = max(0, lb);
        ans = max(ans, lb + r[i]);
        if(!dp[l[i]])
            dp[l[i]] = a[i];
        dp[l[i]] = min(dp[l[i]], a[i]);
        sz = max(sz, l[i] + 1);
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
1
10
9 2 3 4 9 8 7 5 6 1
*/
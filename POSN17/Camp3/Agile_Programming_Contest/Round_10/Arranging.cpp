/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Weighted Interval Scheduling
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

struct INTERVAL {
    int st, en, w, state;
    bool operator < (const INTERVAL &o) const {
        if(en != o.en)
            return en < o.en;
        return st < o.st;
    }
};

INTERVAL itv[3 * MaxN];

int a[MaxN];
int l[2][MaxN], r[2][MaxN], w[MaxN];
int en[3 * MaxN];
int dp[2][3 * MaxN];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        r[0][a[i]] = i;
        w[a[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        if(r[0][a[i]] != i)
            r[1][a[i]] = i;
    }
    for(int i = n; i >= 1; i--) {
        l[0][a[i]] = i;
    }
    for(int i = n; i >= 1; i--) {
        if(l[0][a[i]] != i)
            l[1][a[i]] = i;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(l[0][i] && r[0][i]) {
            itv[++cnt] = {l[0][i], r[0][i], w[i], 0};
        }
        if(l[0][i] && r[1][i]) {
            itv[++cnt] = {l[0][i], r[1][i], w[i] - 1, 1};
        }
        if(l[1][i] && r[0][i]) {
            itv[++cnt] = {l[1][i], r[0][i], w[i] - 1, 1};
        }
    }
    sort(itv + 1, itv + 1 + cnt);
    for(int i = 1; i <= cnt; i++) {
        en[i] = itv[i].en;
    }
    for(int i = 1; i <= cnt; i++) {
        int ub = lower_bound(en + 1, en + 1 + cnt, itv[i].st) - (en + 1);
        dp[0][i] = dp[0][i - 1];
        dp[1][i] = dp[1][i - 1];
        if(itv[i].state) {
            dp[1][i] = max(dp[1][i], dp[0][ub] + itv[i].w);
        }
        else {
            dp[0][i] = max(dp[0][i], dp[0][ub] + itv[i].w);
            dp[1][i] = max(dp[1][i], dp[1][ub] + itv[i].w);
        }
    }
    if(k)
        printf("%d\n", n - dp[1][cnt]);
    else
        printf("%d\n", n - dp[0][cnt]);
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
10 1
1 2 1 1 2 3 4 3 4 3
*/
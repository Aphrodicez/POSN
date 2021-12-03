/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math + Dynamic Programming + Quicksum + Prime Factorization
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
const int MaxK = 1e7 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

vector <int> prime_factor;
bitset <MaxK> isNegative;
int a[MaxN];
int qs[MaxK];
int dp[MaxN];

void solve() {
    int z, k, n;
    scanf("%d %d %d", &z, &k, &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int sq = sqrt(k);
    int val = k;
    for(int i = 2; i <= sq; i++) {
        if(val % i == 0)
            prime_factor.emplace_back(i);
        while(val % i == 0) {
            val /= i;
        }
    }
    if(val > 1)
        prime_factor.emplace_back(val);
    isNegative.set();
    for(int p : prime_factor) {
        for(int i = 0; i < k; i += p)
            isNegative[i] = 0;
    }
    for(int i = 1; i < k; i++) {
        qs[i] = qs[i - 1] + isNegative[i];
    }
    int ans = 0;
    int mn = INF, mx = -INF;
    for(int i = 1; i <= n; i++) {
        dp[i] = a[i] - 2 * (qs[k - 1] * (a[i] / k) + qs[a[i] % k]);
        if(i > 1)
            ans = max({ans, dp[i] - mn, mx - dp[i]});
        dp[i] += (isNegative[a[i] % k] ? 1 : -1);
        if(i == 1) {
            mn = mx = dp[i];
            continue;
        }
        mn = min(mn, dp[i]);
        mx = max(mx, dp[i]);
    }
    printf("%d\n", ans);
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
10 6 3
5 7 10

11 6 5
1 2 7 10 11

13 7 4
2 7 8 12

15 24 5
2 5 12 13 14
*/
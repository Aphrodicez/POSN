/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;
const int MOD = 1e9 + 7;

void TESTCASE() {
    
}

long long dp[MaxN], qs[MaxN];

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] %= MOD;
        dp[i] = (qs[i - 1] * qs[i]) % MOD;
        qs[i] = (qs[i] + qs[i - 1]) % MOD;
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        long long ans = (((dp[r] - dp[l - 1]) % MOD) + MOD) % MOD;
        ans = ((ans - (qs[l - 1] * (qs[r] - qs[l - 1])) % MOD) + MOD) % MOD;
        cout << ans << "\n";
    }
}

int main() {
    setIO();
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
9 2
3 2 1 6 8 2 4 4 2
3 7
1 1
*/
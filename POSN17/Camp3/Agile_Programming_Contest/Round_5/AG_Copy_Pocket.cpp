/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Stars and Bars + Find Inverse [Fermat's little theorem] + Bitmasking
    Status	: Accepted
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

const int N = 2e1 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

void TESTCASE() {

}

long long lim[N];

long long fermat(long long a, long long b) {
    if(b == 0)
        return 1ll % MOD;
    if(b == 1)
        return a % MOD;
    long long product = fermat(a, b / 2);
    product *= product;
    product %= MOD;
    if(b % 2) {
        product *= a;
        product %= MOD;
    }
    return product % MOD;
}

long long nCr(long long n, long long r) {
    long long nFact, rFact;
    nFact = rFact = 1;
    r = min(r, n - r);
    for(long long i = (n - r) + 1; i <= n; i++) {
        nFact = (nFact * (i % MOD)) % MOD;
    }
    for(long long i = 1; i <= r; i++) {
        rFact = (rFact * (i % MOD)) % MOD;
    }
    return (nFact * fermat(rFact % MOD, MOD - 2)) % MOD;
}

void solve() {
    long long n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> lim[i];
    long long ans = 0;
    for(int i = 0; i <= (1 << n) - 1; i++) {
        long long now = s;
        for(int j = 0; j < n; j++) {
            if((1 << j) & i) {
                now -= (lim[j] + 1);
            }
        }
        if(now < 0)
            continue;
        if(__builtin_popcount(i) % 2)
            ans -= nCr(now + n - 1, n - 1);
        else
            ans += nCr(now + n - 1, n - 1);
        ans %= MOD;
    }
    cout << (ans + MOD) % MOD << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
    while(q--) {
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
2 3
1 3

1
2 4
2 2

1
3 5
1 3 2
*/

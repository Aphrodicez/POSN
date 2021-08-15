/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Catalan Number + Find Inverse
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
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

const int N = 2e6 + 10;
const int M = 2e5 + 10;
const int MOD = 2e6 + 3;

i64 fact[N];

i64 inverse(i64 b) {
    for(i64 i = 0; i < MOD; i++) {
        if((b * i) % MOD == 1)
            return i;
    }
}

void TESTCASE() {
    i64 n;
    int m;
    cin >> n >> m;
    i64 b;
    b = fact[n];
    b *= fact[n];
    b %= MOD;
    b *= (n + 1);
    b %= MOD;
    i64 ans;
    ans = (fact[2 * n] * inverse(b)) % MOD;
    if(m == 1)
        ans = (fact[n] - ans + MOD) % MOD;
    cout << ans << "\n";
}

void solve() {
    fact[0] = 1;
    for(int i = 1; i <= N - 10; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    int q = 1;
    cin >> q;
    while(q--) {
        TESTCASE();
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
3 1
4 1 
5 0
*/
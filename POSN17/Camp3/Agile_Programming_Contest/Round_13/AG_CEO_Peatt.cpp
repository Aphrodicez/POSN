/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Stars and Bars
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

const int MaxN = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 9901;

struct GRAPH {
    
};

int fact[MaxN];
int qs[MaxN];
vector <int> ep;

int mod_of_power(int a, int b) {
    if(b == 1)
        return a % MOD;
    int res = mod_of_power(a, b / 2);
    res = (res * res) % MOD;
    if(b % 2)
        res = (res * a) % MOD;
    return res;
}

int nCr(int n, int r) {
    return (fact[n] * mod_of_power(((fact[r] * fact[n - r]) % MOD), MOD - 2)) % MOD;
}

void solve() {
    fact[0] = 1;
    for(int i = 1; i <= 1000; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        memset(qs, 0, sizeof (qs));
        ep.clear();
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &qs[i]);
            qs[i] += qs[i - 1];
        }
        ep.emplace_back(1);
        ep.emplace_back(qs[n]);
        for(int i = 1; i <= m; i++) {
            int idx;
            scanf("%d", &idx);
            ep.emplace_back(idx);
        }
        sort(ep.begin(), ep.end());
        int ans = 1;
        for(int i = 0; i < int(ep.size()) - 1; i++) {
            int l = lower_bound(qs + 1, qs + 1 + n, ep[i]) - qs;
            int r = lower_bound(qs + 1, qs + 1 + n, ep[i + 1]) - qs;
            ans *= nCr(ep[i + 1] - ep[i], r - l);
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
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
2
4 0
2
2
2
2
3 2
3
1
7
2
4
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Ad - Hoc ] + Math + Closed Formula Recurrence Relation
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
const int MOD = 1e9 + 9;

struct GRAPH {
    
};

long long factorial[MaxN];
long long dp[MaxN];

void solve() {
    int n = 1e6;
    factorial[3] = 6 / 3;
    for(long long i = 4; i <= n; i++) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        long long n;
        scanf("%lld", &n);
        printf("%lld\n", ((n - 2) * factorial[n]) % MOD);
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
3
3
4
5
*/
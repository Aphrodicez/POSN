/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Modulo
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

int idx[MaxN];
long long qs[MaxN];

int a[MaxN];

int n;

int mod(int val) {
    return ((val % n) + n) % n;
}

int move(int u, int v) {
    return mod(idx[v % n] - idx[u % n]);
}

void solve() {
    int k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        idx[a[i] % n] = i;
    }
    long long ans = 0;
    k--;
    if(a[1] != 1) {
        ans += move(a[1], 1);
    }
    for(int i = 1; i <= n; i++) {
        qs[i] = qs[i - 1] + move(mod(i), mod(i + 1));
    }
    ans += (qs[n] * (k / n)) + qs[k % n];
    printf("%lld\n", ans);
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
4 6
4
2
1
3

4 20
3
2
1
4

1 81
1
*/
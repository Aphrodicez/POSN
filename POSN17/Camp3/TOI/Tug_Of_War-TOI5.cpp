/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Greedy Algorithm
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

const int MaxN = 2e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

long long a[MaxN], b[MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += abs(b[i] - a[i]);
    }
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
3
-5
-10
-7
8
6
10

2
80
-100
-70
90
*/
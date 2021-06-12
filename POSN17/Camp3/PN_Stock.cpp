/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming + Greedy Algorithm
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

const int N = 1e6 + 10;
const int M = 2e5 + 10;

int a[N], l[N], r[N];

void solve() {
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    int n, mn, mx, ans = -2e9;
    scanf("%d", &n);
    scanf("%d", &a[1]);
    mn = a[1];
    for(int i = 2; i <= n; i++) {
        scanf("%d", &a[i]);
        l[i] = max(a[i] - mn, l[i - 1]);
        mn = min(mn, a[i]);
    }
    mx = a[n];
    for(int i = n - 1; i >= 1; i--) {
        r[i] = max(mx - a[i], r[i + 1]);
        mx = max(mx, a[i]);
    }
    for(int i = 1; i < n; i++) {
        ans = max(ans, l[i] + r[i + 1]);
    }
    printf("%d\n", ans);
}

int main() {
    int q;
    scanf("%d", &q);
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
10
2 5 2 5 7 7 34 12 5 21
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

const int N = 1e6 + 10;
const int M = 2e5 + 10;

i64 a[N], l[N], r[N];

void solve() {
    i64 n, mn, mx;
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    scanf("%lld", &n);
    scanf("%lld", &a[1]);
    mn = a[1];
    for(int i = 2; i <= n; i++){
        scanf("%lld", &a[i]);
        l[i] = max(l[i - 1], a[i] - mn);
        mn = min(mn, a[i]);
    }
    mx = a[n];
    for(int i = n - 1; i >= 1; i--){
        r[i] = max(r[i + 1], mx - a[i]);
        mx = max(mx, a[i]);
    }
    i64 ans = 0;
    for(int i = 1; i < n; i++){
        ans = max(ans, l[i] + r[i + 1]);
    }
    printf("%lld", ans);
}

int main() {
    i64 q;
    scanf("%lld", &q);
    while(q--){
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

1
4
1 2 9 10
*/
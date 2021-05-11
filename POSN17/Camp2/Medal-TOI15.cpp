/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

using i64 = long long;

const int N = 5e5 + 10;
const int M = 2e5 + 10;

i64 a[N], b[N];

void solve() {
    i64 n, ans = 0;
    scanf("%lld", &n);
    for(i64 i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(i64 i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater <int>());
    for(i64 i = 1; i <= n; i++)
        a[i] += b[i];
    sort(a + 1, a + n + 1);
    for(i64 i = 2; i <= n; i++)
        ans += a[i] - a[i - 1];
    printf("%lld", ans);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
158 168 139
132 104 140
2
11 28
68 38
3
9 1 7
6 4 4
*/
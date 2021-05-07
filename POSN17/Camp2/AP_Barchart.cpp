/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Stack Implementation
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

using i64 = long long;

const int N = 1e5 + 10;

i64 h[N], l[N], r[N];

void solve(){
    i64 n, ans = 0;
    cin >> n;
    for(i64 i = 1; i <= n; i++){
        cin >> h[i];
        i64 now = i - 1;
        while(now > 0 && (h[i] <= h[now]))
            now = l[now];
        l[i] = now;
    }
    for(i64 i = n; i >= 1; i--){
        i64 now = i + 1;
        while(now < n + 1 && (h[i] <= h[now]))
            now = r[now];
        r[i] = now;
    }
    for(i64 i = 1; i <= n; i++){
        ans = max(ans, (r[i] - l[i] - 1) * h[i]);
    }
    cout << ans << "\n";
}

int main() {
    i64 q;
    cin >> q;
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
2
6
2 1 5 6 2 3
3
100 100 100
*/
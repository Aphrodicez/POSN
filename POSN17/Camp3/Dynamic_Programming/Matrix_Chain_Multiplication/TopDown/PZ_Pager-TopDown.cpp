/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication [Top Down] + Compress
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

const int N = 2e2 + 10;
const int M = 2e5 + 10;

i64 li[N], ri[N], ci[N], cost[2 * N][2 * N], dp[2 * N][2 * N];

map <i64, i64> mp;

i64 divide(i64 l, i64 r) {
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l + 1 >= r)
        return dp[l][r] = cost[l][r];
    i64 mx = 0;
    for(i64 mid = l + 1; mid <= r - 1; mid++) {
        divide(l, mid);
        divide(mid, r);
        mx = max(mx, dp[l][mid] + dp[mid][r]);
    }
    return dp[l][r] = cost[l][r] + mx;
}

void solve() {
    memset(cost, 0, sizeof cost);
    memset(dp, -1, sizeof dp);
    mp.clear();
    i64 n;
    cin >> n;
    for(i64 i = 1; i <= n; i++) {
        cin >> li[i] >> ri[i] >> ci[i];
        mp[li[i]] = 1;
        mp[ri[i]] = 1;
    }
    i64 cnt = 1;
    for(auto x: mp) {
        mp[x.first] = cnt++;
    }
    cnt--;
    for(i64 i = 1; i <= n; i++) {
        cost[mp[li[i]]][mp[ri[i]]] = ci[i];
    }
    divide(1, cnt);
    cout << dp[1][cnt] << '\n';
}

int main() {
    setIO();
    i64 q;
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
2
4
1 10 1000
2 5 200
3 7 2000
5 9 500
3
10 12 200
10 15 400
13 17 400
*/
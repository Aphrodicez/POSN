/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Increasing Subsequence
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (i64)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const i64 d4i[] = {-1, 0, 1, 0};
const i64 d4j[] = {0, 1, 0, -1};
const i64 d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const i64 d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const i64 N = 1e5 + 10;
const i64 M = 2e5 + 10;

i64 qs[N], dp[N];

void solve() {
    memset(dp, 0, sizeof dp);
    i64 n, num;
    cin >> n;
    for(i64 i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] += qs[i - 1];
    }
    i64 cnt = 0, idx;
    for(i64 i = 1; i <= n; i++) {
        if(qs[i] <= 0)
            continue;
        idx = lower_bound(dp, dp + cnt, qs[i]) - dp;
        if(idx == cnt)
            cnt++;
        dp[idx] = qs[i];
    }
    cout << idx + 1 << '\n';
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
1
5
10
-2
-30
40
-1
*/
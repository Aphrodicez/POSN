/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Non-Increasing Subsequence
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

struct PEOPLE {
    int s, k;
    bool operator < (const PEOPLE &o) const {
        if(s != o.s)
            return s < o.s;
        return k > o.k;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int dp[N];

PEOPLE a[N];

void solve() {
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].k;
    }
    sort(a + 1, a + n + 1);
    int idx, cnt = 0;
    for(int i = 1; i <= n; i++) {
        idx = upper_bound(dp, dp + cnt, a[i].k * -1) - dp;
        if(idx == cnt)
            cnt++;
        dp[idx] = a[i].k * -1;
    }
    cout << cnt << '\n';
}

int main() {
    setIO();
    int q;
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
3
1 3
3 4
2 2
6
3 4
4 6
11 3
15 2
7 5
1 8
*/
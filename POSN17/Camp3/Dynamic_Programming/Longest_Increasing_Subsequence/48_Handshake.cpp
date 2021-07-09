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
    i64 val; /// xi + v * ti
    i64 minusVal; /// xj - v * tj
    bool operator < (const PEOPLE &o) const {
        if(val != o.val)
            return val < o.val;
        return minusVal < o.minusVal;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

i64 lis[N];
PEOPLE a[N];

void solve() {
    memset(lis, 0, sizeof lis);
    i64 n, v, x, t;
    cin >> n >> v;
    for(int i = 1; i <= n; i++) {
        cin >> x >> t;
        a[i].val = x + v * t;
        a[i].minusVal = x - v * t;
    }
    sort(a + 1, a + n + 1);
    i64 cnt = 0, idx;
    for(int i = 1; i <= n; i++) {
        idx = upper_bound(lis, lis + cnt, a[i].minusVal * -1) - lis;
        if(idx == cnt)
            cnt++;
        lis[idx] = a[i].minusVal * -1;
    }
    cout << cnt << '\n';
}

int main() {
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
4 1
1 1
1 2
2 2
3 3
*/
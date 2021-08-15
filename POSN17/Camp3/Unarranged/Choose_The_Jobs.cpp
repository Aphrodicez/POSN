/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Interval Scheduling
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
#define dec(x) fixed << setprecision(x)
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
    int st, en, val;
    bool operator < (const GRAPH &o) const {
        if(en != o.en)
            return en < o.en;
        return st < o.st;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

GRAPH a[N];

int dp[N], enarr[N];

void solve() {
    int n;
    cin >> n;
    int st, en, val;
    for(int i = 1; i <= n; i++)
        cin >> a[i].st >> a[i].en >> a[i].val;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        enarr[i] = a[i].en;
    for(int i = 1; i <= n; i++) {
        int idx = lower_bound(enarr + 1, enarr + n + 1, a[i].st) - (enarr + 1);
        dp[i] = max(dp[i - 1], dp[idx] + a[i].val);
    }
    cout << dp[n] << "\n";
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
1 5 2
2 6 3
6 8 2

4
1 3 2
4 6 2
2 5 8
4 5 3
*/
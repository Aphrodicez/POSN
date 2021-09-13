/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Binary Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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
    
};

const int MaxN = 1e6 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int a[MaxN];

void solve() {
    int n, m, q, L;
    cin >> n >> m >> q >> L;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    while(q--) {
        int last = 0;
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            int idx;
            cin >> idx;
            int lb = lower_bound(a + 1, a + n + 1, max(last + 1, idx - L)) - a - 1;
            int ub = upper_bound(a + 1, a + n + 1, idx + L) - a - 1;
            ans += ub - lb;
            last = idx + L;
        }
        cout << ans << "\n";
    }
}

int main() {
    setIO();
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
3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001
*/
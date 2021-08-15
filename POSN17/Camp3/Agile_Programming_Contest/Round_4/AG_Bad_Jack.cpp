/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Greedy + Math + Dynamic Programming + Heap
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

struct HEAP {
    i64 val;
    bool operator < (const HEAP &o) const {
        return val < o.val;
    }
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;
const int K = 1e6 + 10;

void TESTCASE() {
    
}

i64 row[N], col[N];

i64 mxrow[K], mxcol[K];

priority_queue <HEAP> pq;

void solve() {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    i64 r, c, k, d;
    cin >> r >> c >> k >> d;
    i64 val;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> val;
            row[i] += val;
            col[j] += val;
        }
    }
    for(int i = 1; i <= r; i++)
        pq.push({row[i]});
    for(int i = 1; i <= k; i++) {
        i64 val = pq.top().val;
        pq.pop();
        mxrow[i] = mxrow[i - 1] + val;
        pq.push({val - d * c});
    }
    while(!pq.empty())
        pq.pop();
    for(int j = 1; j <= c; j++)
        pq.push({col[j]});
    for(int i = 1; i <= k; i++) {
        i64 val = pq.top().val;
        pq.pop();
        mxcol[i] = mxcol[i - 1] + val;
        pq.push({val - d * r});
    }
    while(!pq.empty())
        pq.pop();
    i64 ans = -2e18;
    for(i64 i = 0; i <= k; i++) {
        ans = max(ans, mxrow[i] + mxcol[k - i] - d * (i * (k - i)));
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
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
2 2 2 2
1 3
2 4
2 2 5 2
1 3
2 4

1
2 2 10 2
1 3
2 4
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [ Range Update Point Query ]
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

const int MaxN = 1e4 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int n, m;

int tree[MaxN];

void upd(int idx, int val) {
    while(idx <= n + m) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    int k, q;
    cin >> n >> m >> k >> q;
    q += k;
    int opr;
    while(q--) {
        cin >> opr;
        int i, j;
        cin >> i >> j;
        if(opr == 1) {
            int sz;
            cin >> sz;
            int l = j;
            int r = l + sz - 1;
            r = min(r, m);
            l += (i - 1);
            r += (i - 1);
            upd(l, 1);
            upd(r + 1, -1);
        }
        if(opr == 2) {
            int idx = j + (i - 1);
            cout << query(idx) << "\n";
        }
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
5 5 6 5
1 1 1 4
1 1 3 3
2 3 2
1 2 1 5
1 2 4 2
1 2 4 2
1 4 2 3
2 4 2
2 1 4
2 5 3
2 5 5
*/

/*
5 5 6 5
1 1 1 4
1 1 3 3
1 2 1 5
1 2 4 2
1 2 4 2
1 4 2 3
2 5 1
2 5 2
2 5 3
2 5 4
2 5 5
*/
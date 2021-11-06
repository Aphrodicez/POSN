/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Segment Tree [ Lazy Propagation ]
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

int n;

bitset <4 * MaxN> lazy;

struct LAZY_SEGMENT {
    int tree[4 * MaxN];
    void update(int now, int ql, int qr, int l = 1, int r = n) {
        if(lazy[now]) {
            lazy[2 * now] = 1 - lazy[2 * now];
            lazy[2 * now + 1] = 1 - lazy[2 * now + 1];
            lazy[now] = 0;
            tree[now] = (r - l + 1) - tree[now];
        }
        if(r < ql || qr < l) {
            return;
        }
        if(ql <= l && r <= qr) {
            tree[now] = (r - l + 1) - tree[now];
            lazy[2 * now] = 1 - lazy[2 * now];
            lazy[2 * now + 1] = 1 - lazy[2 * now + 1];
            return;
        }
        int mid = l + (r - l) / 2;
        update(now * 2, ql, qr, l, mid);
        update(now * 2 + 1, ql, qr, mid + 1, r);
        tree[now] = tree[now * 2] + tree[now * 2 + 1];
    }
    int query(int now, int ql, int qr, int l = 1, int r = n) {
        if(lazy[now]) {
            lazy[2 * now] = 1 - lazy[2 * now];
            lazy[2 * now + 1] = 1 - lazy[2 * now + 1];
            lazy[now] = 0;
            tree[now] = (r - l + 1) - tree[now];
        }
        if(r < ql || qr < l) {
            return 0;
        }
        if(ql <= l && r <= qr) {
            return tree[now];
        }
        int mid = l + (r - l) / 2;
        return query(now * 2, ql, qr, l, mid) + query(now * 2 + 1, ql, qr, mid + 1, r);
    }
};

LAZY_SEGMENT lazy_segment;

void TESTCASE() {
    
}

void solve() {
    int q;
    cin >> n >> q;
    while(q--) {
        bool opr;
        cin >> opr;
        int l, r;
        cin >> l >> r;
        if(!opr) {
            lazy_segment.update(1, l, r);
            continue;
        }
        if(opr) {
            cout << lazy_segment.query(1, l, r) << "\n";
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
4 5
0 1 2
0 2 4
1 2 3
0 2 4
1 1 3
*/
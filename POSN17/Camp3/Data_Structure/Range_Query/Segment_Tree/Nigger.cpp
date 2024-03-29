/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Segment Tree [ Lazy Propagation ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int n;

struct SEGMENT_TREE {
    int tree[4 * MaxN];
    bool lazy[4 * MaxN];

    void update(int now, int ql, int qr, int l = 1, int r = n) {
        if(lazy[now]) {
            lazy[now * 2] ^= 1;
            lazy[now * 2 + 1] ^= 1;
            lazy[now] = false;
            tree[now] = (r - l + 1) - tree[now];
        }
        if(qr < l || r < ql)
            return ;
        if(ql <= l && r <= qr) {
            lazy[now * 2] ^= 1;
            lazy[now * 2 + 1] ^= 1;
            tree[now] = (r - l + 1) - tree[now];
            return ;
        }
        int mid = l + (r - l) / 2;
        update(now * 2, ql, qr, l, mid);
        update(now * 2 + 1, ql, qr, mid + 1, r);
        tree[now] = tree[now * 2] + tree[now * 2 + 1];
    }

    int query(int now, int ql, int qr, int l = 1, int r = n) {
        if(lazy[now]) {
            lazy[now * 2] ^= 1;
            lazy[now * 2 + 1] ^= 1;
            lazy[now] = false;
            tree[now] = (r - l + 1) - tree[now];
        }
        if(qr < l || r < ql)
            return 0;
        if(ql <= l && r <= qr) {
            return tree[now];
        }
        int mid = l + (r - l) / 2;
        return query(now * 2, ql, qr, l, mid) + query(now * 2 + 1, ql, qr, mid + 1, r);
    }
};

SEGMENT_TREE segment_tree;

void solve() {
    int m;
    cin >> n >> m;
    while(m--) {
        bool opr;
        cin >> opr;
        if(!opr) {
            int l, r;
            cin >> l >> r;
            segment_tree.update(1, l, r);
            continue;
        }
        if(opr) {
            int l, r;
            cin >> l >> r;
            cout << segment_tree.query(1, l, r) << "\n";
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
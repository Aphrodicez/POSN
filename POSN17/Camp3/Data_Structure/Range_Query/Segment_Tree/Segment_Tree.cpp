/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Segment Tree [ Range Maximum Query ]
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
int a[MaxN];

struct SEGMENT_TREE {
    int tree[4 * MaxN];

    void build(int now, int l = 1, int r = n) {
        if(l == r) {
            tree[now] = a[l];
            return ;
        }
        int mid = l + (r - l) / 2;
        build(now * 2, l, mid);
        build(now * 2 + 1, mid + 1, r);
        tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
    }

    void update(int now, int idx, int val, int l = 1, int r = n) {
        if(r < idx || idx < l)
            return ;
        if(l == r) {
            tree[now] = val;
            return ;
        }
        int mid = l + (r - l) / 2;
        update(now * 2, idx, val, l, mid);
        update(now * 2 + 1, idx, val, mid + 1, r);
        tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
    }

    int query(int now, int ql, int qr, int l = 1, int r = n) {
        if(r < ql || qr < l)
            return -INF;
        if(ql <= l && r <= qr) {
            return tree[now];
        }
        int mid = l + (r - l) / 2;
        return max(query(now * 2, ql, qr, l, mid), query(now * 2 + 1, ql, qr, mid + 1, r));
    }
};

SEGMENT_TREE segment_tree;

void solve() {
    int m;
    cin >> n >> m;
    segment_tree.build(1, 1, n);
    while(m--) {
        char opr;
        cin >> opr;
        if(opr == 'U') {
            int idx, val;
            cin >> idx >> val;
            a[idx] = val;
            segment_tree.update(1, idx, val, 1, n);
            continue;
        }
        if(opr == 'P') {
            int l, r;
            cin >> l >> r;
            cout << segment_tree.query(1, l, r, 1, n) << "\n";
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
5 4
U 1 -14
U 1 -1
P 2 2
P 3 5

6 7
U 5 280
U 1 7
P 1 2
P 3 5
U 4 -873760809
U 2 -392
P 1 1
*/
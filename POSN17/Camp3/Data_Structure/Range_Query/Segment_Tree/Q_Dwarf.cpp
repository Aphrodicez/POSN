/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Segment Tree [ Range Minimum + Maximum Query ] + Bucket Sort
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

const int MaxN = 2e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int n;
int a[MaxN];
int pos[MaxN];

struct NODE {
    int mn, mx;
};

struct SEGMENT_TREE {
    NODE tree[4 * MaxN];

    void build(int now, int l = 1, int r = n) {
        if(l == r) {
            tree[now] = {pos[l], pos[l]};
            return ;
        }
        int mid = l + (r - l) / 2;
        build(now * 2, l, mid);
        build(now * 2 + 1, mid + 1, r);
        tree[now] = {min(tree[now * 2].mn, tree[now * 2 + 1].mn), max(tree[now * 2].mx, tree[now * 2 + 1].mx)};
    }

    void update(int now, int idx, int val, int l = 1, int r = n) {
        if(r < idx || idx < l)
            return ;
        if(l == r) {
            tree[now] = {val, val};
            return ;
        }
        int mid = l + (r - l) / 2;
        update(now * 2, idx, val, l, mid);
        update(now * 2 + 1, idx, val, mid + 1, r);
        tree[now] = {min(tree[now * 2].mn, tree[now * 2 + 1].mn), max(tree[now * 2].mx, tree[now * 2 + 1].mx)};
    }

    NODE query(int now, int ql, int qr, int l = 1, int r = n) {
        if(r < ql || qr < l)
            return {INF, -INF};
        if(ql <= l && r <= qr) {
            return tree[now];
        }
        int mid = l + (r - l) / 2;
        NODE subl = query(now * 2, ql, qr, l, mid);
        NODE subr = query(now * 2 + 1, ql, qr, mid + 1, r);
        return {min(subl.mn, subr.mn), max(subl.mx, subr.mx)};
    }
};

SEGMENT_TREE segment_tree;

void solve() {
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    segment_tree.build(1);
    while(m--) {
        int opr;
        cin >> opr;
        if(opr == 1) {
            int l, r;
            cin >> l >> r;
            segment_tree.update(1, a[l], r);
            segment_tree.update(1, a[r], l);
            swap(a[l], a[r]);
            continue;
        }
        if(opr == 2) {
            int l, r;
            cin >> l >> r;
            NODE res = segment_tree.query(1, l, r);
            if((res.mx - res.mn + 1) == (r - l + 1)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
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
7 7
4 7 3 5 1 2 6
2 1 7
1 3 7
2 4 6
2 4 7
2 1 4
1 1 4
2 1 4
*/
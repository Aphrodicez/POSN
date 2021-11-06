/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Segment Tree [ Minimum - Maximum Range Query ] + Bucket Sort
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

const int MaxN = 2e5 + 10;
const int MaxM = 2e5 + 10;

const int INF = 1e9 + 10;

int a[MaxN];
int pos[MaxN];
int n;

struct SEGMENT_TREE {
    pair <int, int> tree[4 * MaxN];
    void build(int now, int l = 1, int r = n) {
        if(l == r) {
            tree[now] = make_pair(pos[l], pos[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(now * 2, l, mid);
        build(now * 2 + 1, mid + 1, r);
        pair <int, int> subl = tree[now * 2];
        pair <int, int> subr = tree[now * 2 + 1];
        tree[now] = make_pair(min(subl.first, subr.first), max(subl.second, subr.second));
    }
    void update(int now, int idx, int val, int l = 1, int r = n) {
        if(l > idx || r < idx) {
            return ;
        }
        if(l == r) {
            tree[now] = make_pair(val, val);
            return ;
        }
        int mid = l + (r - l) / 2;
        update(now * 2, idx, val, l, mid);
        update(now * 2 + 1, idx, val, mid + 1, r);
        pair <int, int> subl = tree[now * 2];
        pair <int, int> subr = tree[now * 2 + 1];
        tree[now] = make_pair(min(subl.first, subr.first), max(subl.second, subr.second));
        return ;
    }
    pair <int, int> query(int now, int ql, int qr, int l = 1, int r = n) {
        if(r < ql || qr < l) {
            return make_pair(INF, -INF);
        }
        if(ql <= l && r <= qr) {
            return tree[now];
        }
        int mid = l + (r - l) / 2;
        pair <int, int> subl = query(now * 2, ql, qr, l, mid);
        pair <int, int> subr = query(now * 2 + 1, ql, qr, mid + 1, r);
        return make_pair(min(subl.first, subr.first), max(subl.second, subr.second));
    }
};

SEGMENT_TREE segment_tree;

void solve() {
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    segment_tree.build(1, 1, n);
    while(q--) {
        int opr;
        cin >> opr;
        int l, r;
        if(opr == 1) {
            cin >> l >> r;
            segment_tree.update(1, a[l], r);
            segment_tree.update(1, a[r], l);
            swap(a[l], a[r]);
        }
        if(opr == 2) {
            cin >> l >> r;
            pair <int, int> res = segment_tree.query(1, l, r);
            if((res.second - res.first + 1) == (r - l + 1))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
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
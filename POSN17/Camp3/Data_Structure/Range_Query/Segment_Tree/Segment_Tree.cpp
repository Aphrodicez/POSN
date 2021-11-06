/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Segment Tree [ Maximum Range Query ]
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int a[MaxN];
vector <int> segment_tree(4 * MaxN, -(1e9 + 10));

void build(int l, int r, int now) {
    if(l == r) {
        segment_tree[now] = a[l];
        return ;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, now * 2);
    build(mid + 1, r, now * 2 + 1);
    segment_tree[now] = max(segment_tree[now * 2], segment_tree[now * 2 + 1]); 
}

void update(int l, int r, int now, int idx, int val) {
    if(l > idx || r < idx) {
        return ;
    }
    if(l == r) {
        segment_tree[now] = val;
        return ;
    }
    int mid = l + (r - l) / 2;
    update(l, mid, now * 2, idx, val);
    update(mid + 1, r, now * 2 + 1, idx, val);
    segment_tree[now] = max(segment_tree[now * 2], segment_tree[now * 2 + 1]);
}

int query(int l, int r, int now, int ql, int qr) {
    if(l > qr || r < ql) {
        return -(1e9 + 10);
    }
    if(l >= ql && r <= qr) {
        return segment_tree[now];
    }
    int mid = l + (r - l) / 2;
    return max(query(l, mid, now * 2, ql, qr), query(mid + 1, r, now * 2 + 1, ql, qr));
}

void solve() {
    int n, q;
    cin >> n >> q;
    build(1, n, 1);
    while(q--) {
        char opr;
        cin >> opr;
        if(opr == 'U') {
            int idx, val;
            cin >> idx >> val;
            update(1, n, 1, idx, val);
            continue;
        }
        if(opr == 'P') {
            int l, r;
            cin >> l >> r;
            cout << query(1, n, 1, l, r) << "\n";
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
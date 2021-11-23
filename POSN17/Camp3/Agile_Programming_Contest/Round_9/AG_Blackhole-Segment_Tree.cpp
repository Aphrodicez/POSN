/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Lazy Segment Tree + Euler Tour
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

vector <int> adj[MaxN];

int n;

int level[MaxN];
int l[MaxN], r[MaxN];
int cnt = 0;

struct SEGMENT_TREE {    
    pair <int, int> tree[4 * 2 * MaxN];
    pair <int, int> isLazy[4 * 2 * MaxN];
    void build() {
        for(int i = 1; i <= 4 * 2 * n; i++) {
            tree[i] = make_pair(INF, INF);
            isLazy[i] = make_pair(INF, INF);
        }
    }
    void lazy(int now, pair <int, int> val) {
        tree[now] = min(tree[now], val);
        isLazy[now] = min(isLazy[now], val);
    }
    void clear(int now) {
        lazy(now * 2, isLazy[now]);
        lazy(now * 2 + 1, isLazy[now]);
        isLazy[now] = make_pair(INF, INF);
    }
    void update(int now, int ql, int qr, pair <int, int> val, int l = 1, int r = 2 * n) {
        if(qr < l || r < ql)
            return ;
        if(ql <= l && r <= qr) {
            lazy(now, val);
            return ;
        }
        if(isLazy[now] != make_pair(INF, INF)) {
            clear(now);
        }
        int mid = l + (r - l) / 2;
        if(ql <= mid)
            update(now * 2, ql, qr, val, l, mid);
        if(mid + 1 <= qr)
            update(now * 2 + 1, ql, qr, val, mid + 1, r);
        tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
    }
    pair <int, int> query(int now, int ql, int qr, int l = 1, int r = 2 * n) {
        if(qr < l || r < ql) {
            return make_pair(INF, INF);    
        }
        if(ql <= l && r <= qr) {
            return tree[now];
        }
        if(isLazy[now] != make_pair(INF, INF)) {
            clear(now);
        }
        int mid = l + (r - l) / 2;     
        return min(query(now * 2, ql, qr, l, mid), query(now * 2 + 1, ql, qr, mid + 1, r));
    }
};

void euler_tour(int u, int p) {
    level[u] = level[p] + 1;
    l[u] = ++cnt;
    for(int x : adj[u]) {
        if(x == p)
            continue;
        euler_tour(x, u);
    }
    r[u] = ++cnt;
}

SEGMENT_TREE segtree;

void solve() {
    int q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    euler_tour(1, 1);
    segtree.build();
    while(q--) {
        int opr;
        scanf("%d", &opr);
        if(!opr) {
            int u;
            scanf("%d", &u);
            segtree.update(1, l[u], r[u], make_pair(level[u], u));
            continue;
        }
        if(opr) {
            int u;
            scanf("%d", &u);
            int ans = segtree.query(1, l[u], l[u]).second;
            printf("%d\n", ans == INF ? -1 : ans);
        }
    }
}

int main() {
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
9 6
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8
1 3
0 8
1 6
1 7
0 2
1 9
*/
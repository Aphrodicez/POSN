/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [ Compressed Number ] + Dynamic Programming
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

struct FENWICK_TREE {
    int tree[MaxN];
    void update(int idx, int val) {
        for(; idx <= n; idx += idx & -idx) {
            tree[idx] = max(tree[idx], val);
        }
    }
    int query(int idx, int mx = 0) {
        for(; idx > 0; idx -= idx & -idx) {
            mx = max(mx, tree[idx]);
        }
        return mx;
    }
    void clear() {
        memset(tree, 0, sizeof (tree));
    }
};

int a[MaxN];
vector <int> sorted;
int l[MaxN], r[MaxN];
int mp[MaxN];
FENWICK_TREE fenwick;

void solve() {
    memset(mp, 0, sizeof mp);
    fenwick.clear();
    sorted.clear();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sorted.emplace_back(a[i]);
    }
    sort(sorted.begin(), sorted.end());
    sorted.resize(unique(sorted.begin(), sorted.end()) - sorted.begin());
    for(int i = 1; i <= n; i++) {
        a[i] = (lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin()) + 1;
    }
    l[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] <= a[i - 1]) {
            l[i] = 1;
            continue;
        }
        l[i] = l[i - 1] + 1;
    }
    r[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] >= a[i + 1]) {
            r[i] = 1;
            continue;
        }
        r[i] = r[i + 1] + 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, fenwick.query(a[i] - 1) + r[i]);
        fenwick.update(a[i], l[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int q = 1;
    scanf("%d", &q);
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
1
10
9 2 3 4 9 8 7 5 6 1
*/
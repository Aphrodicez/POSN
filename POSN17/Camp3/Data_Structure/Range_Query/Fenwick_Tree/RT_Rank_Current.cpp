/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree
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

const int MaxN = 3e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int n;

struct FENWICK_TREE {
    int tree[MaxN];
    void update(int idx, int val) {
        for(; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    int query(int idx, int sum = 0) {
        for(; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
};

int a[MaxN];

unordered_map <int, int> mp;
vector <pair <int, int>> query;

FENWICK_TREE fenwick_tree;

void solve() {
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int opr, val;
        cin >> opr >> val;
        if(opr == 1) {
            a[++cnt] = val;
        }
        query.emplace_back(opr, val);
    }
    sort(a + 1, a + 1 + cnt);
    n = cnt;
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            mp[a[i]] = ++cnt;
        }
    }
    for(auto x : query) {
        int opr = x.first;
        int idx = mp[x.second];
        if(opr == 1) {
            fenwick_tree.update(idx, 1);
        }
        if(opr == 2) {
            cout << fenwick_tree.query(idx) << "\n";
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
12
1 5
1 6
1 4
2 4
2 5
2 6
1 8
1 1
2 5
2 1
2 4
2 6
*/
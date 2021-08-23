/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [Inversion Count]
    Status	: Accepted
    Created	: 21 August 2021 [01:32]
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
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

struct A {
    i64 idx, val;
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int TREE_SIZE = 3e5 + 10;

void TESTCASE() {
    
}

i64 a[N], b[N], leftInversion[N], tree[TREE_SIZE];

unordered_map <i64, int> mapp;

i64 query(int idx) {
    i64 sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void upd(int idx, i64 val) {
    while(idx <= 300003) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void solve() {
    mapp.clear();
    memset(leftInversion, 0, sizeof leftInversion);
    memset(tree, 0, sizeof tree);
    int n;
    cin >> n;   
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++) {
        mapp[b[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = mapp[a[i]];
        leftInversion[i] = query(n - a[i]);
        upd(n + 1 - a[i], 1ll);
    }
    i64 ans = 0;
    memset(tree, 0, sizeof tree);
    for(int i = n; i >= 1; i--) {
        ans += query(a[i] - 1) * leftInversion[i];
        upd(a[i], 1ll);
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
4
9 7 5 3
4
1 4 3 2
3
2 3 1
*/
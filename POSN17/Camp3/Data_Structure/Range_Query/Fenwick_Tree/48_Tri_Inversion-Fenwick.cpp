/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [Inversion Count] + Math
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

struct TREE {

};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int n;

int a[MaxN], sorted[MaxN];

long long tree[MaxN];

long long LeftInversion[MaxN];

unordered_map <int, int> mapp;

void upd(int idx, long long val) {
    while(idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long long query(int idx) {
    long long sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    mapp.clear();
    memset(tree, 0, sizeof tree);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memcpy(sorted, a, sizeof sorted);
    sort(sorted + 1, sorted + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(sorted[i] > sorted[i - 1])
            mapp[sorted[i]] = ++cnt;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = mapp[a[i]];
        int idx = n - a[i] + 1;
        LeftInversion[i] = query(idx - 1);
        upd(idx, 1);
    }
    memset(tree, 0, sizeof tree);
    long long ans = 0;
    for(int i = n; i >= 1; i--) {
        ans += query(a[i] - 1) * LeftInversion[i];
        upd(a[i], 1);
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
3
4
9 7 5 3
4
1 4 3 2
3
2 3 1
*/
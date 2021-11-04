/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree + Math
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
const int MOD = 1e9 + 7;

void TESTCASE() {
    
}

long long a[MaxN], sorted[MaxN];
unordered_map <long long, long long> mp;
long long fenwick_tree[MaxN];

int n;

void update(int idx, long long val) {
    val %= MOD;
    while(idx <= n) {
        fenwick_tree[idx] += val;
        fenwick_tree[idx] %= MOD;
        idx += (idx & -idx);
    }
}

long long query(int idx) {
    long long sum = 0;
    while(idx > 0) {
        sum += fenwick_tree[idx];
        sum %= MOD;
        idx -= (idx & -idx);
    }
    return sum;
}

void solve() {
    memset(fenwick_tree, 0, sizeof fenwick_tree);
    mp.clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(sorted[i] != sorted[i - 1])
            mp[sorted[i]] = ++cnt;
    }
    for(int i = 1; i <= n; i++) {
        update(mp[a[i]], (query(mp[a[i]]) * a[i]) + a[i] - (query(mp[a[i]]) - query(mp[a[i]] - 1)));
    }
    cout << (query(n) + MOD) % MOD << "\n";
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
1
10
3
1 2 2
5
1 2 3 4 5
*/
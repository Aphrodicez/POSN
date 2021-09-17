/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [ Range Query ]
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

const int MaxN = 1e6;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long tree[MaxN];

void upd(int idx, long long val) {
    int rb = 1e6 + 3;
    while(idx <= rb) {
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
    int n, m;
    cin >> n >> m;
    string s;
    int idx;
    long long val;
    int l, r;
    for(int i = 1; i <= m; i++) {
        cin >> s;
        if(s == "Bury") {
            cin >> val >> idx;
            upd(idx, val);
        }
        if(s == "Find") {
            cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
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
10 5
Bury 5 5
Bury 10 7
Find 3 7
Bury 20 8
Find 6 10
*/
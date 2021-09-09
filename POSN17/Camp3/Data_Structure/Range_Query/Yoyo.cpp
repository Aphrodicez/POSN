/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [ Point Query ]
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

const int MaxN = 5e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long tree[MaxN];

int n;

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
    int m;
    cin >> n >> m;
    string s;
    while(m--) {
        cin >> s;
        if(s == "Yoyo") {
            long long val;
            int l, r;
            cin >> val >> l >> r;
            if(l > r)
                swap(l, r);
            upd(l, val);
            upd(r + 1, -val);
        }
        if(s == "Ask") {
            int idx;
            cin >> idx;
            cout << query(idx) << "\n";
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
7 6
Yoyo 10 4 7
Yoyo 15 1 5
Ask 4
Yoyo 5 3 6
Ask 5
Ask 7
*/
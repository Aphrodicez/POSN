/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Fenwick Tree [Inversion Count]
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

int n;

long long tree[MaxN];

int a[MaxN], b[MaxN];

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
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memcpy(b, a, sizeof a);
    sort(b + 1, b + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(b[i] > b[i - 1])
            mapp[b[i]] = ++cnt;
    }
    long long ans = 0;
    for(int i = n; i >= 1; i--) {
        ans += query(mapp[a[i]] - 1);
        upd(mapp[a[i]], 1); 
    }
    cout << ans << "\n";
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
5
2 4 1 3 5
*/
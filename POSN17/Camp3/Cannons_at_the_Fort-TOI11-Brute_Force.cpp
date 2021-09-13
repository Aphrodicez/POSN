/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force + Two Pointer
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int MaxN = 1e6 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int a[MaxN];

void solve() {
    int n, m, q, L;
    cin >> n >> m >> q >> L;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while(q--) {
        cin >> m;
        int idx;
        int it = 1;
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            cin >> idx;
            while(it <= n && a[it] < idx - L)
                it++;
            while(it <= n && a[it] <= idx + L) {
                it++;
                ans++;
            }
        }
        cout << ans << "\n";
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
3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001
*/
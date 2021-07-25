/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

struct GRAPH {
    
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

i64 h[N], l[N], r[N];

void solve() {
    memset(h, 0, sizeof (h));
    int n;
    cin >> n;
    i64 ans = 0;
    l[1] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        l[i] = i - 1;
        while(l[i] > 0 && h[i] <= h[l[i]])
            l[i] = l[l[i]];
    }
    for(int i = n; i >= 1; i--) {
        r[i] = i + 1;
        while(r[i] < n + 1 && h[i] <= h[r[i]])
            r[i] = r[r[i]];
        ans = max(ans, (r[i] - l[i] - 1) * h[i]);
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q;
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
2
6
2 1 5 6 2 3
3
100 100 100
*/
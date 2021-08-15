/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
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

i64 a[N], dpl[N], dpr[N];

void solve() {
    memset(dpl, 0, sizeof dpl);
    memset(dpr, 0, sizeof dpr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    i64 sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        dpl[i] = max(dpl[i - 1], sum);
        sum = max(sum, 0ll);
    }
    sum = 0;
    for(int i = n; i >= 1; i--) {
        sum += a[i];
        dpr[i] = max(dpr[i + 1], sum);
        sum = max(sum, 0ll);
    }
    i64 ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dpl[i] + dpr[i + 1]);
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
1
5
4
-6
3
-2
6
*/
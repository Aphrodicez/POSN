/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Two Pointer + Binary Search + Dynamic Programming [ Ad - Hoc ]
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;
const int MOD = 95959;

void TESTCASE() {
    
}

int a[MaxN], qs[MaxN];

void solve() {
    int n, k;
    cin >> n >> k;
    cin >> a[1];
    qs[1] = 1;
    int last = 1;
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        int lb = lower_bound(a + last, a + i + 1, a[i] - k) - a;
        last = lb;
        qs[i] = (qs[i - 1] + (qs[i - 1] - qs[lb - 1] + MOD) % MOD) % MOD;
    }
    cout << (qs[n] - qs[n - 1] + MOD) % MOD << "\n";
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
2
5 10
1
3
5
7
9
5 7
1
3
5
7
9
*/
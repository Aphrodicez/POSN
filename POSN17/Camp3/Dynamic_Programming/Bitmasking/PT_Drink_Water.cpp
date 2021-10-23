/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bitmasking [ Top Down ]
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

const int MaxN = 2e1 + 10;
const int MaxM = 2e5 + 10;
const int N = 20;

void TESTCASE() {
    
}

long long a[MaxN][MaxN];
long long dp[(1 << N)];

long long ans = 1e18;

int n, k;

void recursion(int mask, long long sum) {
    if(sum >= ans || sum >= dp[mask])
        return;
    dp[mask] = sum;
    if(__builtin_popcount(mask) == k) {
        ans = min(ans, dp[mask]);
        return;
    }
    for(int child = 1; child <= n; child++) {
        if(!(mask & (1 << (child - 1)))) {
            continue;
        }
        long long cost = 1e18;
        for(int parent = 1; parent <= n; parent++) {
            if(parent == child || !(mask & (1 << (child - 1)))) {
                continue;
            }
            if(mask & (1 << (parent - 1))) {
                cost = min(cost, a[child][parent]);
            }
        }
        recursion(mask - (1 << (child - 1)), sum + cost);
    }
    return;
}

void solve() {
    ans = 1e18;
    cin >> n >> k;
    for(int i = 1; i <= (1 << n) - 1; i++)
        dp[i] = 1e18;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    recursion((1 << n) - 1, 0);
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
1
5 2
0 5 4 3 2
7 0 4 4 4
3 3 0 1 2
4 3 1 0 5
4 5 5 5 0
*/  
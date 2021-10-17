/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bitmasking
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

const int MaxN = 1e4 + 10;
const int MaxK = 8;

void TESTCASE() {
    
}

long long w[MaxN], a[MaxN];
long long dp[(1 << MaxK)];

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= (1 << k) - 1; i++) {
        dp[i] = 1e12;
    }
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        long long p;
        for(int j = 0; j < k; j++) {
            cin >> p;
            if(p)
                a[i] |= (1 << j);
        }
    }
    dp[0] = 0;
    for(int i = 0; i <= (1 << k) - 1; i++) {
        if(dp[i] == 1e12)
            continue;
        for(int j = 1; j <= n; j++) {
            dp[i | a[j]] = min(dp[i | a[j]], dp[i] + w[j]);
        }
    }
    cout << dp[(1 << k) - 1] << "\n";
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
5 3
10 1 0 1
30 0 1 1
5 1 0 0
4 0 0 1
150 1 1 1
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc]
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

const int MaxN = 1e3;
const int MaxM = 1e4;
const int MOD = 1e9 + 7;

void TESTCASE() {
    
}

int dp[2][MaxM + 10];

void solve() {
    int n, d;
    cin >> n >> d;
    dp[0][0] = 1;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum = 0;
        for(int j = 0; j <= d; j++) {
            sum = (sum + dp[(i & 1) ^ 1][j]) % MOD;
            if(j - i >= 0)
                sum = (sum - dp[(i & 1) ^ 1][j - i] + MOD) % MOD;
            dp[i & 1][j] = sum;
        }
    }
    cout << dp[n & 1][d] << "\n";
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
10 1
*/
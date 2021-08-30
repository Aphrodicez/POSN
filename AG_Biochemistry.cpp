/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc] + Game
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

const int N = 1e6 + 10;
const int M = 2e5 + 10;

void TESTCASE() {

}

long long dp[N];

void solve() {
    memset(dp, 0, sizeof dp);
    long long n, a, b;
    cin >> n >> a >> b;
    long long j = 1;
    dp[1] = -b;
    dp[2] = a;
    for(int i = 3; i <= n; i++) {
        while(dp[j] <= dp[i - j] + b && j + 1 <= i)
            j++;
        dp[i] = min(dp[i - j + 1] + b, dp[j]) + a;
    }
    dp[1] += b;
    cout << dp[n] << "\n";
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
2
2 1 1
9 3 2
*/

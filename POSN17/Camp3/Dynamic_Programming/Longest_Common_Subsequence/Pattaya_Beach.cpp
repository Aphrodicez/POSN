/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Common Subsequence
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

const int N = 3e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int a[N], b[N];

int dp[2][N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= n; j++)
        cin >> b[j];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j]) {
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
                continue;
            }
            dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
        }
    }
    cout << dp[n % 2][n];
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
5
3
1
5
2
4
1
2
5
4
3
*/
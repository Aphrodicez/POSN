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

const int N = 5e3 + 10;
const int M = 2e5 + 10;

i64 a[N], b[N];

i64 dp[2][N];

void solve() {
    memset(dp, 0, sizeof dp);
    i64 n, m;
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int j = 1; j <= m; j++)
        scanf("%lld", &b[j]);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i % 2][j] = max({dp[i % 2][j - 1], dp[(i + 1) % 2][j], dp[(i + 1) % 2][j - 1]+ abs(a[i] - b[j])});
        }
    }
    printf("%lld\n", dp[n % 2][m]);
}

int main() {
    i64 q;
    scanf("%lld", &q);
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
4 4
1 2 3 4
1 2 3 4
*/
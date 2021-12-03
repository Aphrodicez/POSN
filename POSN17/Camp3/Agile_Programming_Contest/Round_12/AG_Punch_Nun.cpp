/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Ad - Hoc ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 2e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int dp[2][MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        dp[i & 1][0] = max(dp[i & 1 ^ 1][0], dp[i & 1 ^ 1][0 + 2] - val);
        for(int j = 1; j <= i; j++) {
            dp[i & 1][j] = max(dp[i & 1 ^ 1][j - 1] + val, dp[i & 1 ^ 1][j + 2] - val);
        }
    }
    printf("%d\n", dp[n & 1][0]);
}

int main() {
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
7
1 2 3 4 5 6 7

9
5 5 5 5 5 5 5 5 100
*/
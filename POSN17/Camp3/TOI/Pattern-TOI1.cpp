/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
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

const int MaxN = 5e4 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int dp[MaxN][70 + 10];

void solve() {
    int n;
    scanf("%d", &n);
    int r = 0, c = 70;
    for(int it = 1; it <= n; it++) {
        int i, j, sz;
        scanf("%d %d %d", &i, &j, &sz);
        dp[i][j]++;
        dp[i][min(70 + 1, j + sz)]--;
        r = max(r, i);
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dp[i][j] += dp[i][j - 1];
            printf(dp[i][j] ? "x" : "o");
        }
        printf("\n");
    }
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
4
1 1 10
2 3 9
3 5 25
2 20 2

*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Knapsack ] + Math
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

const int MaxN = 5e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

long long dp[MaxN][MaxN];

void solve() {
    int n, X, Y;
    scanf("%d %d %d", &n, &X, &Y);
    for(int i = 0; i <= Y; i++) {
        for(int j = 0; j <= X; j++) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for(int k = 1; k <= n; k++) {
        int x, y;
        long long w;
        scanf("%d %d %lld", &x, &y, &w);
        x = min(x, X), y = min(y, Y);
        for(int j = X; j >= 0; j--) {
            for(int i = Y; i >= 0; i--) {
                dp[i][j] = min(dp[i][j], dp[max(i - y, 0)][max(j - x, 0)] + w);
            }
        }
    }
    if(dp[Y][X] == 1e18)
        printf("-1\n");
    else
        printf("%lld\n", dp[Y][X]);
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
3 10 10
10 10 5
5 5 1
6 6 2

5 10 10
1 2 2
2 1 3
3 1 4
1 3 1
4 2 1
*/
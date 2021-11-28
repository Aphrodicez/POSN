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

int dp[MaxN][MaxN];

void solve() {
    dp[0][0] = 1;
    for(int k = 0; k <= 32; k++) {
        for(int l = 0; l <= 32; l++) {
            if(k == 0 && l == 0)
                continue;
            for(int i = 500; i - k >= 0; i--) {
                for(int j = 500; j - l >= 0; j--) {
                    if(dp[i - k][j - l])
                        dp[i][j] = max(dp[i][j], dp[i - k][j - l] + 1);
                }
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%d\n", dp[i][j] - 1);
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
2 0
3 0
3 1
4 5
*/
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

const int MaxN = 3e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int dp[MaxN];

void solve() {
    int w, h, n;
    scanf("%d %d %d", &w, &h, &n);
    int l, r, sz;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &l, &sz);
        l++;
        r = min(w, l + sz - 1);
        dp[l]++;
        dp[r + 1]--;
    }
    int ansa = 0, ansb = 0;
    for(int i = 1; i <= w; i++) {
        dp[i] += dp[i - 1];
        ansa += (!dp[i]);
        ansb += (dp[i] == 1);
    }
    printf("%d %d\n", ansa * h, ansb * h);
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
7 3 3
1 2
5 3
2 2

7 3 2
0 3
2 4
*/
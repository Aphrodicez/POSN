/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void solve() {
    int n;
    scanf("%d", &n);
    v(int) qs(n + 1, 0);
    for(int i = 1; i <= n; i++){
        scanf("%d", &qs[i]);
        qs[i] += qs[i - 1];
    }
    v(v(int)) dp(n + 1, (v(int) (n + 1, 0)));
    for(int sz = 2; sz <= n; sz++){
        for(int start = 1; start + sz - 1 <= n; start++){
            int l = start, r = start + sz - 1;
            dp[l][r] = 1e9;
            for(int mid = l; mid < r; mid++){
                int sum = ((qs[mid] - qs[l - 1]) % 100) * ((qs[r] - qs[mid]) % 100);
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r] + sum);
            }
        }
    }
    printf("%d\n", dp[1][n]);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--){
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
2
98 97
3
40 60 20
*/
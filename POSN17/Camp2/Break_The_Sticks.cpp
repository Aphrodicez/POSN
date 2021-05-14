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

const int N = 5e1 + 10;
const int M = 2e5 + 10;

int a[N], dp[N][N];

void solve() {
    int len, n;
    scanf("%d %d", &len, &n);    
    n += 2;
    for(int i = 2; i <= n - 1; i++)
        scanf("%d", &a[i]);
    a[1] = 0;
    a[n] = len;
    for(int sz = 3; sz <= n; sz++){
        for(int start = 1; start + sz - 1 <= n; start++){
            int l = start, r = start + sz - 1;
            dp[l][r] = 1e9;
            for(int mid = l + 1; mid < r; mid++){
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid][r] + a[r] - a[l]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
10 3
2 4 7

100 3
25 50 75

10 4
4 5 7 8
*/
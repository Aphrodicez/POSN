/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication [Top Down]
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

const int N = 1e3 + 10;
const int M = 2e5 + 10;

int dp[N][N];

char a[N];

int divide(int l, int r) {
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l == r)
        return dp[l][r] = 0;
    if(a[l] == a[r])
        dp[l][r] = 1;
    else
        dp[l][r] = 0;
    int mx = 0;
    for(int mid = l; mid <= r - 1; mid++) {
        divide(l, mid);
        divide(mid + 1, r);
        mx = max(mx, dp[l][mid] + dp[mid + 1][r]);
    }
    return dp[l][r] = max(dp[l][r] + dp[l + 1][r - 1], mx);
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << divide(1, n) << '\n';
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
6
U B N B O U

12
U B O U B O U B O U B O

13
N U B O B U O N B O N U O
*/
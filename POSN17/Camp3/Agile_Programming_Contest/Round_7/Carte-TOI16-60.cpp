/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

const int MaxN = 4e2 + 10;
const int MaxM = 2e5 + 10;
const int MaxK = 30 + 10;

void TESTCASE() {
    
}

int K;

int a[MaxN], dp[MaxN][MaxN], dp2[MaxK][MaxN][MaxN];

void solve() {
    int n;
    cin >> n;
    for(int k = 1; k <= K; k++) { 
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i - 1; j++) {
                dp[i][j] = dp2[k][i][j] = 0;
            }
            for(int j = i; j <= n; j++) {
                dp[i][j] = dp2[k][i][j] = 1e9;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = dp2[1][i][i] = 1;
    }
    for(int sz = 2; sz <= n; sz++) {
        for(int l = 1; l + sz - 1 <= n; l++) {
            int r = l + sz - 1;
            dp[l][r] = dp2[1][l][r] = 1 + dp[l + 1][r];
            for(int k = 2; k <= K; k++) {
                for(int mid = l + 1; mid <= r; mid++) {
                    if(a[l] != a[mid])
                        continue;
                    dp2[k][l][r] = min(dp2[k][l][r], dp[l + 1][mid - 1] + dp2[k - 1][mid][r]);
                    dp[l][r] = min(dp[l][r], dp2[k][l][r]);
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q >> K;
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
3 5
12
7 2 6 6 6 6 6 6 6 6 6 6
10
5 2 5 7 3 8 3 1 2 7
5
8 8 4 4 4
*/
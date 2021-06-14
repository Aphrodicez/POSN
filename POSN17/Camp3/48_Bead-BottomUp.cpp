/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication [Bottom Up]
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

const int N = 1e2 + 10;
const int M = 2e5 + 10;

int qs[N], dp[N][N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] += qs[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for(int sz = 2; sz <= n; sz++) {
        for(int start = 1; start + sz - 1 <= n; start++) {
            int l = start, r = start + sz - 1;
            for(int mid = l; mid <= r - 1; mid++) {
                int suml = qs[r] - qs[mid];
                int sumr = qs[mid] - qs[l - 1];
                suml %= 100;
                sumr %= 100;
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r] + suml * sumr);
            }
        }
    }
    cout << dp[1][n] << '\n';
}

int main() {
    setIO();
    int q;
    cin >> q;
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
2
2
98 97
3
40 60 20
*/
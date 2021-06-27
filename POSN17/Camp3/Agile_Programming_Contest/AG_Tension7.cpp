/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication [BottomUp]
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

const int N = 6e2 + 10;
const int M = 2e5 + 10;

i64 qs[N];

i64 dp[N][N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] += qs[i - 1];
        dp[i][i] = 0;
    }
    for(int sz = 2; sz <= n; sz++) {
        for(int start = 1; start + sz - 1 <= n; start++) {
            int l = start, r = start + sz - 1;
            dp[l][r] = 0;
            for(int mid = l; mid <= r - 1; mid++) {
                i64 suml = qs[mid] - qs[l - 1];
                i64 sumr = qs[r] - qs[mid];
                if(suml < sumr)
                    suml *= 2;
                else
                    sumr *= 2;
                dp[l][r] = max(dp[l][r], suml + sumr + dp[l][mid] + dp[mid + 1][r]);
            }
        }
    }
    cout << dp[1][n] << "\n";
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
3
4
1 4 5 2
4
1 2 3 5
3
99 9 9
*/
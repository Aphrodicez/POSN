/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Knapsack ]
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long dp[20100 + 10];

void solve() {
    memset(dp, 0, sizeof dp);
    long long n;
    cin >> n;
    int all = 0;
    int val;
    long long k = n / 2;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        val += 101;
        all += val;
        for(int j = 20100; j > val; j--) {
            long long last = dp[j - val] % (1ll << (k - 1));
            if(last) {
                dp[j] |= (last << 1ll);
            }
        }
        dp[val] |= 1ll;
    }
    int ans = 1e9;
    for(int i = 0; i <= 20100; i++) {
        if(dp[i] & (1ll << (k - 1))) {
            ans = min(ans, abs(2 * i - all));
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
2
2
100
90
4
-1
2
5
10

1
8
-19 
-11 
46 
0 
45 
-20 
-32 
38
*/
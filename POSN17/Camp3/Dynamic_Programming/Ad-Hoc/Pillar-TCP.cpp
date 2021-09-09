/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc]
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int a[N];

int dp[N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n <= 2) {
        cout << n << " " << 0 << "\n";
        return ;
    }
    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i + 1] - a[i] >= 1 && a[i + 1] - a[i] <= 2)
            dp[i] = dp[i + 1] + 1;
        else
            dp[i] = 1;
    }
    int ans = n, mx = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        if(i < n && dp[i + 1] + 1 >= mx) {
            if(dp[i + 1] + 1 > mx)
                ans = i;
            else
                ans = min(ans, i);
            mx = dp[i + 1] + 1;
        }
        if(i > 1 && sum + 1 >= mx) {
            if(sum + 1 > mx)
                ans = i;
            else
                ans = min(ans, i);
            mx = sum + 1;
        }
        if(i > 1 && i < n && a[i + 1] - a[i - 1] >= 2 && a[i + 1] - a[i - 1] <= 4) {
            if(sum + dp[i + 1] + 1 >= mx) {
                if(sum + dp[i + 1] + 1 > mx)
                    ans = i;
                else
                    ans = min(ans, i);
                mx = sum + dp[i + 1] + 1;
            }
        }
        if(a[i] - a[i - 1] >= 1 && a[i] - a[i - 1] <= 2)
            sum = sum + 1;
        else
            sum = 1;
    }
    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] - a[i + 1] >= 1 && a[i] - a[i + 1] <= 2)
            dp[i] = dp[i + 1] + 1;
        else
            dp[i] = 1;
    }
    sum = 0;
    for(int i = 1; i <= n; i++) {
        if(i < n && dp[i + 1] + 1 >= mx) {
            if(dp[i + 1] + 1 > mx)
                ans = i;
            else
                ans = min(ans, i);
            mx = dp[i + 1] + 1;
        }
        if(i > 1 && sum + 1 >= mx) {
            if(sum + 1 > mx)
                ans = i;
            else
                ans = min(ans, i);
            mx = sum + 1;
        }
        if(i > 1 && i < n && a[i - 1] - a[i + 1] >= 2 && a[i - 1] - a[i + 1] <= 4) {
            if(sum + dp[i + 1] + 1 >= mx) {
                if(sum + dp[i + 1] + 1 > mx)
                    ans = i;
                else
                    ans = min(ans, i);
                mx = sum + dp[i + 1] + 1;
            }
        }
        if(a[i - 1] - a[i] >= 1 && a[i - 1] - a[i] <= 2)
            sum = sum + 1;
        else
            sum = 1;
    }
    cout << mx << " " << ans - 1 << "\n";
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
12
20 10 11 11 15 10 17 16 10 12 20 20
7
0 0 0 0 0 0 0
*/
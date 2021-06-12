/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Common Subsequence
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

struct DP {
    int days, minutes;
    bool operator < (const DP &o) const {
        if(days != o.days)
            return days < o.days;
        return minutes < o.minutes;
    }
};

int timeInDays;

DP operator+(const DP a, const DP b) {
    if(a.minutes + b.minutes > timeInDays)
        return DP{a.days + 1, b.minutes};
    return DP{a.days, a.minutes + b.minutes}; 
}

const int N = 1e3 + 10;
const int M = 2e5 + 10;

int a[N], b[N];

DP dp[N][N];

void solve() {
    int n;
    scanf("%d", &timeInDays);
    scanf("%d", &n);
    dp[0][0] = DP{1, 0};
    for(int i = 1; i <= n; i++) { 
        scanf("%d", &a[i]);
        dp[i][0] = dp[i - 1][0] + DP{0, a[i]};
    }
    for(int j = 1; j <= n; j++){
        scanf("%d", &b[j]);
        dp[0][j] = dp[0][j - 1] + DP{0, b[j]};
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i][j - 1] + DP{0, b[j]}, dp[i - 1][j] + DP{0, a[i]});
        }
    }
    printf("%d\n", dp[n][n].days);
    printf("%d\n", dp[n][n].minutes);
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
8 
4 
4 5 6 4 
3 3 2 4 

8 
6 
2 3 4 5 3 2 
6 2 3 2 4 5 

10 
12 
1 7 5 4 3 6 2 3 4 5 1 8 
3 4 4 8 3 9 1 7 3 2 4 5
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Matrix Chain Multiplication + Greedy Algorithm
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

void TESTCASE() {
    
}

int a[MaxN], dp[MaxN][MaxN], used[MaxN][MaxN];

int K;

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i - 1; j++) {
            dp[i][j] = used[i][j] = 0;
        }
        for(int j = i; j <= n; j++) {
            dp[i][j] = used[i][j] = 1e9;
        }
        dp[i][i] = used[i][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int sz = 2; sz <= n; sz++) {
        for(int l = 1; l + sz - 1 <= n; l++) {
            int r = l + sz - 1;
            dp[l][r] = 1 + dp[l + 1][r];
            used[l][r] = 1;
            for(int mid = l + 1; mid <= r; mid++) {
                if(a[l] != a[mid])
                    continue;
                if(used[mid][r] >= K)
                    continue;
                int sum = dp[l + 1][mid - 1] + dp[mid][r];
                if(dp[l][r] == sum)
                    used[l][r] = min(used[l][r], 1 + used[mid][r]);
                if(dp[l][r] > sum) {
                    dp[l][r] = sum;
                    used[l][r] = 1 + used[mid][r];
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}

int main() {
    setIO();
    int Q = 1;
    cin >> Q >> K;
    for(int i = 1; i <= Q; i++) {
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
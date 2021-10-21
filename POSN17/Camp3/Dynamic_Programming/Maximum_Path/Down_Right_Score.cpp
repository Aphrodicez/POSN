/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Maximum Path]
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

const int N = 25e1 + 10;
const int M = 2e5 + 10;

int dp[N][N];

void TESTCASE() {
    
}

void solve() {
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[r][c] << "\n";
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
3 3
5 19 47
75 3 1
4 5 24
*/
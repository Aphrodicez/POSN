/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc]
    Status	: Accepted
    Created	: 24 August 2021 [23:53]
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

const int N = 1e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int a[N];

int dp[N][N];

int n;

int play(int u, int last) {
    if(u < 1 || u > n)
        return 1e9;
    if(u == n)
        return a[n];
    if(dp[last][u] != -1)
        return dp[last][u];
    return dp[last][u] = a[u] + min(play(u + last + 1, last + 1), play(u - last, last));
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << play(2, 1) << "\n";
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
1
2
3
4
5
6
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programing On Tree
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

const int N = 3e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[N];

int dp[N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        dp[i] = 1;
    int u, v;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[min(u, v)].push_back(max(u, v));
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int x : g[i]) {
            dp[x] = max(dp[x], dp[i] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
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
9
1 2
2 9
1 7
6 8
2 6
3 9
4 9
5 4
*/  
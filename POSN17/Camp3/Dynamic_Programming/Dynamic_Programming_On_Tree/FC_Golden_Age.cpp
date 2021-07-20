/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
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

const int N = 5e3 + 10;
const int M = 2e5 + 10;
const int K = 1e2 + 10;

void TESTCASE() {
    
}

i64 tree[N];
i64 dp[K][N];

int n;

i64 dfs(int u, int k) {
    if(!k || u > n)
        return 0;
    if(dp[k][u] != -1)
        return dp[k][u];
    int nextk = k - 1;
    i64 sum = 0;
    for(int l = 0; l <= nextk; l++) {
        int r = nextk - l;
        sum = max(sum, dfs(u * 2, l) + dfs(u * 2 + 1, r));
    }
    return dp[k][u] = tree[u] + sum;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> tree[i];
    }
    i64 ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i, k));
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
10 5
3 7 1 9 6 2 6 5 4 1
*/
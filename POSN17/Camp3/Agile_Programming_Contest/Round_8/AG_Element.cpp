/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math + Depth First Search
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

const int MaxN = 1e3 + 10;
const int MaxM = 2e5 + 10;
const int MaxK = 60 + 10;

void TESTCASE() {
    
}

int dp[MaxN];
int contain[MaxN][MaxK];
int sum[MaxK];
vector <int> g[MaxN];

void dfs(int u, int p) {
    for(int x : g[u]) {
        if(x == p)
            continue;
        if(dp[x] <= dp[u] + 1)
            continue;
        dp[x] = dp[u] + 1;
        dfs(x, u);
    }
}

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for(int i = 0; i <= n - 1; i++) {
        dp[i] = 70;
    }
    int u, v;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[v].emplace_back(u);
    }
    dp[0] = 0;
    dfs(0, 0);
    int mx = 0;
    for(int i = 0; i <= n - 1; i++) {
        mx = max(mx, dp[i]);
    }
    for(int i = 0; i <= n - 1; i++) {
        dp[i] = mx - dp[i];
    }
    int cnt;
    for(int i = 0; i <= m - 1; i++) {
        cin >> cnt;
        int val;
        for(int j = 1; j <= cnt; j++) {
            cin >> val;
            contain[i][dp[val]]++;
        }
    }
    while(q--) {
        memset(sum, 0, sizeof sum);
        int cnt;
        cin >> cnt;
        int u;
        for(int i = 1; i <= cnt; i++) {
            cin >> u;
            for(int j = 0; j <= k; j++) {
                sum[j] += contain[u][j];
            }
        }
        int ans = 0;
        for(ans = 0; ans < mx && (sum[ans] % 2 == 0); ans++) {
            sum[ans + 1] += sum[ans] / 2;
            sum[ans] %= 2;
        }
        cout << ans << "\n";
    }
}

int main() {
    setIO();
    int q = 1;
    
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
3 4 2 5
1 0
2 0
2 0 1
2 0 2
1 1
1 2
1 0
1 1
2 3 3
2 2 3
3 0 2 3
*/
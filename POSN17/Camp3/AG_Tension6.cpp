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
    int u, w;
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

int dp[N];

void dfsSumRoot(int u, int pa) {
    int sum = 0;
    for(auto x: g[u]) {
        if(x.u == pa)
            continue;
        dfsSumRoot(x.u, u);
        sum += dp[x.u] + x.w;
    }
    dp[u] = sum;
    return ;
}

void dfsAllRoot(int u, int pa) {
    for(auto x: g[u]) {
        if(x.u == pa)
            continue;
        dp[x.u] = dp[u];
        if(x.w == 1)
            dp[x.u]--;
        else
            dp[x.u]++;
        dfsAllRoot(x.u, u);
    }
}

void solve() {
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    dfsSumRoot(1, 1);
    dfsAllRoot(1, 1);
    int ans, mn = n;
    for(int i = 1; i <= n; i++) {
        if(mn > dp[i]) {
            mn = dp[i];
            ans = i;
        }
    }
    cout << mn << " " << ans << "\n";
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
3 1
4 5
4 2
1 6
6 2
*/
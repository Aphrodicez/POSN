/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
    Status	: Accepted
    Created	: 24 August 2021 [00:58]
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

const int N = 4e4 + 10;
const int M = 501;

struct GRAPH {
    int u;
    long long w;
};

struct DIS {
    long long restaurant[M], hotel;
};

DIS dp[N];

unordered_map <int, int> componentName;

int p[N];

bool isHotel[N], isRestaurant[N];

vector <GRAPH> adj[N];

int n, m, r, k;

long long mxDis[M];

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

void dfs(int u, int pa) {
    if(isHotel[u])
        dp[u].hotel = 0;
    if(isRestaurant[u])
        dp[u].restaurant[componentName[find_root(u)]] = 0;
    for(auto x : adj[u]) {
        if(x.u == pa)
            continue;
        dfs(x.u, u);
        for(int i = 1; i <= m; i++) {
            mxDis[i] = max(mxDis[i], dp[u].hotel + dp[x.u].restaurant[i] + x.w);
            mxDis[i] = max(mxDis[i], dp[u].restaurant[i] + dp[x.u].hotel + x.w);
        }
        for(int i = 1; i <= m; i++) {
            dp[u].restaurant[i] = max(dp[u].restaurant[i], dp[x.u].restaurant[i] + x.w);
            dp[u].hotel = max(dp[u].hotel, dp[x.u].hotel + x.w);
        }
    }
}

void solve() {
    componentName.clear();
    memset(dp, 0xc0, sizeof dp);
    memset(mxDis, 0, sizeof mxDis);
    memset(isHotel, false, sizeof isHotel);
    memset(isRestaurant, false, sizeof isRestaurant);
    cin >> n >> m >> r >> k;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        p[i] = i;
    }
    int u, v;
    long long w;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 1; i <= r; i++) {
        cin >> u >> v;
        isRestaurant[u] = isRestaurant[v] = true;
        p[find_root(v)] = find_root(u);
    }
    for(int i = 1; i <= k; i++) {
        cin >> u;
        isHotel[u] = true;
    }
    int componentIdx = 0;
    for(int i = 1; i <= n; i++) {
        if(isRestaurant[i] && !componentName[find_root(i)])
            componentName[find_root(i)] = ++componentIdx;
    }
    dfs(1, 1);
    long long ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += mxDis[i] * 2;
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
    while(q--) {
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
7 2 3 3
1 2 3
2 4 2
3 4 7
4 5 1
5 6 3
5 7 5
1 2
3 5
5 7
1 3 5
5 1 2 3
1 2 4
2 4 3
4 5 1
3 4 2
1 2
2 3
1 3 5
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm + Floyd Warshall's Algorithm + Bitmasking
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
    int u, w, mask;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 2e2 + 10;
const int MaxM = 2e5 + 10;
const int MaxK = 15;

void TESTCASE() {
    
}

vector <GRAPH> friendArr;
int dp[MaxN][MaxN];
int dis[(1 << MaxK)][MaxN];
vector <GRAPH> g[MaxN];
priority_queue <GRAPH> pq;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    friendArr.push_back({1, 0, 0});
    int u, v, w;
    for(int i = 0; i < k; i++) {
        cin >> u;
        friendArr.push_back({u, 0, 1 << i});
    }
    friendArr.push_back({n, 0, 0});
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 1e9;
        }
        dp[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = dp[u][v];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for(int state = 0; state <= (1 << k) - 1; state++) {
        for(int i = 1; i <= n; i++) {
            dis[state][i] = 1e9;
        }
    }
    pq.push({1, 0, 0});
    dis[0][1] = 0;
    while(!pq.empty()) {
        int u = pq.top().u;
        int mask = pq.top().mask;
        pq.pop();
        if(u == n && mask == (1 << k) - 1) {
            cout << dis[(1 << k) - 1][u] << "\n";
            return ;
        }
        for(auto x : friendArr) {
            int nextw = dis[mask][u] + dp[u][x.u];
            int nextmask = mask | x.mask;
            if(dis[nextmask][x.u] <= nextw)
                continue;
            dis[nextmask][x.u] = nextw;
            pq.push({x.u, nextw, nextmask});
        }
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
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4

7 10 2
3 6
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Algorithm Kth State
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
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 2e4 + 10;
const int M = 3e4 + 10;
const int K = 1e2 + 10;

vector <GRAPH> g[N];

int a[N];

vector <int> shopStart[K];

priority_queue <GRAPH> dijk;

void solve() {
    while(!dijk.empty())
        dijk.pop();
    for(int i = 1; i <= 100; i++) 
        shopStart[i].clear();
    int n, m, shopTypeRequired;
    cin >> n >> m >> shopTypeRequired;
    int u, v, w;
    vector <vector <int>> dis(n + 1, vector<int> (110, 1e9));
    for(int i = 1; i <= n; i++)
        g[i].clear();
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dis[i][0] = dis[i][a[i]] = 0;
        shopStart[a[i]].push_back(i);
    }
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int k = 1; k <= 100; k++) {
        if(!shopStart[k].size())
            continue;
        for(int x: shopStart[k]) {
            dijk.push({x, 0});
        }
        while(!dijk.empty()) {
            int u = dijk.top().u;
            int w = dijk.top().w;
            dijk.pop();
            for(auto x: g[u]) {
                if(dis[x.u][k] <= dis[u][k] + x.w)
                    continue;
                dis[x.u][k] = dis[u][k] + x.w;
                dijk.push({x.u, dis[x.u][k]});
            }
        }
    }
    int ans = 2e9;
    for(int i = 1; i <= n; i++) {
        sort(dis[i].begin(), dis[i].end());
        if(dis[i][shopTypeRequired] == 1e9)
            continue;
        int sum = 0;
        for(int j = 1; j <= shopTypeRequired; j++) {
            sum += dis[i][j];
        }
        ans = min(ans, sum);
    }
    cout << (ans == 2e9 ? -1 : ans) << "\n";
}

int main() {
    setIO();
    int q;
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
3 2 2
1 2 3
1 2 1
2 3 3
5 5 3
1 3 4 2 3
1 2 5
2 3 2
3 4 5
4 1 3
4 5 2
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    int u;
    long long w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

vector <GRAPH> g[MaxN];
priority_queue <GRAPH> pq;

vector <long long> dis;

void solve() {
    int n, m;
    cin >> n >> m;
    dis.assign(MaxN, 1e18);
    int u, v;
    long long w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dis[1] = 0;
    pq.push({1, 0});
    while(!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        for(auto x : g[u]) {
            if(dis[x.u] <= dis[u] + x.w)
                continue;
            dis[x.u] = dis[u] + x.w;
            pq.push({x.u, dis[x.u]});
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << "\n";
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
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/
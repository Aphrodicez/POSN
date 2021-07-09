/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Minimum Spanning Tree [Kruskal]
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
    int u, v, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

priority_queue <GRAPH> pq;

int deg[N];

int pa[N];

int find_root(int u) {
    if(pa[u] == u)
        return u;
    return pa[u] = find_root(pa[u]);
}

void solve() {
    while(!pq.empty())
        pq.pop();
    memset(deg, 0, sizeof deg);
    int n;
    cin >> n;
    int w;
    for(int i = 1; i <= n; i++) {
        pa[i] = i;
        for(int j = 1; j <= n; j++) {
            cin >> w;
            if(i <= j)
                continue;
            pq.push({i, j, w});
        }
    }
    while(!pq.empty()) {
        int u = pq.top().u;
        int v = pq.top().v;
        pq.pop();
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            continue;
        pa[rv] = ru;
        deg[u]++;
        deg[v]++;
    }
    int ans = 1, mx = 0;
    for(int i = 1; i <= n; i++) {
        if(mx < deg[i]) {
            mx = deg[i];
            ans = i;
        }
    }
    cout << ans << " " << mx << "\n";
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
1
4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0
*/
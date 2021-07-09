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
    i64 u, v, w;
    bool operator < (const GRAPH &o) const {
        return w < o.w;
    }
};

const int N = 2e5 + 10;
const int M = 2e5 + 10;

i64 pa[N];

priority_queue <GRAPH> pq;

i64 find_root(i64 u) {
    if(pa[u] == u)
        return u;
    return pa[u] = find_root(pa[u]);
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    i64 u, v, w;
    for(i64 i = 1; i <= n; i++)
        pa[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        pq.push({u, v, w - 1});
    }
    i64 ans = 0;
    while(!pq.empty()) {
        i64 u = pq.top().u;
        i64 v = pq.top().v;
        i64 w = pq.top().w;
        pq.pop();
        i64 ru = find_root(u);
        i64 rv = find_root(v);
        if(ru == rv)
            continue;
        pa[ru] = rv;
        ans += w;
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
6 9 
1 2 8 
2 3 6 
1 4 6 
4 2 6 
4 5 8 
2 5 7 
5 6 5 
2 6 9 
3 6 5

4 6 
1 2 1 
3 4 1 
1 3 2 
4 1 3 
2 3 2 
3 1 1 
*/
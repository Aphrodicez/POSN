/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Minimum Spanning Tree [Kruskal] + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (i64)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const i64 d4i[] = {-1, 0, 1, 0};
const i64 d4j[] = {0, 1, 0, -1};
const i64 d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const i64 d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct EDGE {
    i64 u, v, w;
    bool operator < (const EDGE &o) const {
        return w < o.w;
    }
};

const i64 N = 4e4 + 10;
const i64 M = 1e5 + 10;

const i64 MOD = 1e9 + 7;

i64 pa[N];

EDGE edge[M];

i64 find_root(i64 u) {
    if(pa[u] == u)
        return u;
    return find_root(pa[u]);
}

i64 union_root(i64 u) {
    if(pa[u] == u)
        return u;
    return pa[u] = union_root(pa[u]);
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    for(i64 i = 1; i <= n; i++) {
        pa[i] = i;
    }
    i64 u, v, w;
    for(i64 i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        edge[i] = {min(u, v), max(u, v), w};
    }
    sort(edge + 1, edge + m + 1);
    i64 sum = 0, ans = 1;
    for(i64 i = 1; i <= m; ) {
        i64 j = i;
        w = edge[i].w;
        set <pair <i64, i64>> uniqueEdge;
        i64 validCnt = 0;
        while(j <= m) {
            if(w != edge[j].w)
                break;
            i64 u = edge[j].u;
            i64 v = edge[j].v;
            i64 ru = find_root(u);
            i64 rv = find_root(v);
            if(ru != rv){
                validCnt++;
                uniqueEdge.insert(make_pair(min(ru, rv), max(ru, rv)));
            }
            j++;
        }
        i64 componentsCnt = 0;
        j = i;
        while(j <= m) {
            if(w != edge[j].w)
                break;
            i64 u = edge[j].u;
            i64 v = edge[j].v;
            i64 ru = union_root(u);
            i64 rv = union_root(v);
            pa[ru] = rv;
            if(ru != rv) {
                componentsCnt++;
            }
            j++;
        }
        i64 increment = 1;
        if(validCnt == 2 && componentsCnt == 1)
            increment = 2;
        if(validCnt == 3) {
            if(componentsCnt == 1)
                increment = 3;
            if(componentsCnt == 2 && uniqueEdge.size() == 2)
                increment = 2;
            if(componentsCnt == 2 && uniqueEdge.size() == 3)
                increment = 3;
        }
        sum += w * componentsCnt;
        sum %= MOD;
        ans *= increment;
        ans %= MOD;
        i = j;
    }
    cout << sum << " " << ans << "\n";
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
4 5
1 3 2
2 3 2
1 2 1
3 4 1
1 4 2
*/
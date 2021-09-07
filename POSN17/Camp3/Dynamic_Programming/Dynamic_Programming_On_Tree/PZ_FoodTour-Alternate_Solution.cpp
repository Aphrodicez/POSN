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

struct GRAPH {
    int u;
    long long w;
    int villageName;
};

const int N = 4e4 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int p[N];

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

vector <GRAPH> g[N];

bool isHotel[N];

GRAPH firstSubTree[N], secondSubTree[N];

int componentSize[N];

long long mxDis[N];

void dfsSubTree(int u, int pa) {
    for(auto x : g[u]) {
        if(x.u == pa)
            continue;
        dfsSubTree(x.u, u);
        int from = x.u;
        long long sum = 0;
        int villageName = 0;
        if(isHotel[x.u]) {
            sum = 0 + x.w;
            villageName = x.u;
        }
        if(firstSubTree[x.u].w) {
            sum = firstSubTree[x.u].w + x.w;
            villageName = firstSubTree[x.u].villageName;
        }
        if(!sum)
            continue;
        if(secondSubTree[u].w < sum)
            secondSubTree[u] = {from, sum, villageName};
        if(firstSubTree[u].w < secondSubTree[u].w)
            swap(firstSubTree[u], secondSubTree[u]);
    }
}

void dfsFoodTour(int u, int pa) {
    for(auto x : g[u]) {
        if(x.u == pa)
            continue;
        int from = u;
        long long sum = 0;
        int villageName = 0;
        if(isHotel[u]) {
            sum = 0 + x.w;
            villageName = u;
        }
        if((firstSubTree[u].u != x.u) && (firstSubTree[u].w)) {
            sum = firstSubTree[u].w + x.w;
            villageName = firstSubTree[u].villageName;
        }
        else if((secondSubTree[u].u != x.u) && (secondSubTree[u].w)) {
            sum = secondSubTree[u].w + x.w;
            villageName = secondSubTree[u].villageName;
        }
        if(secondSubTree[x.u].w < sum)
            secondSubTree[x.u] = {u, sum, villageName};
        if(firstSubTree[x.u].w < secondSubTree[x.u].w)
            swap(firstSubTree[x.u], secondSubTree[x.u]);
        dfsFoodTour(x.u, u);
    }
}

void solve() {
    memset(componentSize, 0, sizeof componentSize);
    memset(mxDis, 0, sizeof mxDis);
    memset(firstSubTree, 0, sizeof firstSubTree);
    memset(secondSubTree, 0, sizeof secondSubTree);
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        isHotel[i] = false;
        g[i].clear();
    }
    int u, v;
    long long w;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(int i = 1; i <= r; i++) {
        cin >> u >> v;
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            continue;
        p[rv] = ru;
    }
    for(int i = 1; i <= k; i++) {
        cin >> u;
        isHotel[u] = true;
    }
    dfsSubTree(1, 1);
    dfsFoodTour(1, 1);
    for(int i = 1; i <= n; i++) {
        int ri = find_root(i);
        mxDis[ri] = max(mxDis[ri], firstSubTree[i].w);
        componentSize[ri]++;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        if(componentSize[i] > 1) {
            ans += mxDis[i] * 2;
        }
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
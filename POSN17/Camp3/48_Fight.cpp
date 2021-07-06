/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bipartite Check + Binary Search
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
    int u, idx;
};

const int N = 1e5 + 10;
const int M = 3e5 + 10;

void TESTCASE() {
    
}

vector <GRAPH> g[N];

int root[M];

int col[N];

bool BipartiteCheck(int u, int color, int mxidx) {
    if(col[u])
        return col[u] == color;
    col[u] = color;
    for(auto x: g[u]) {
        if(x.idx > mxidx)
            continue;
        if(!BipartiteCheck(x.u, 3 - color, mxidx))
            return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        root[i] = u;
    }
    int l = 1, r = m;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(BipartiteCheck(root[mid], 1, mid))
            l = mid + 1;
        else
            r = mid;
        memset(col, 0, sizeof col);
    }
    cout << l << "\n";
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
6 8
3 4
1 2
5 6
1 6
1 3
4 5
2 4
2 6
*/
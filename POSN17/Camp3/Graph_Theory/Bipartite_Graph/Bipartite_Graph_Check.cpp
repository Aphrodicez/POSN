/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bipartite Check
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
    
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[N];

int col[N];

bool BipartiteCheck(int u, int color) {
    if(col[u])
        return col[u] == color;
    col[u] = color;
    for(auto x : g[u]) {
        if(!BipartiteCheck(x, 3 - color))
            return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int u, v;
    memset(col, 0, sizeof col);
    for(int i = 1; i <= n; i++)
        g[i].clear();
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << (BipartiteCheck(1, 1) ? "yes" : "no") << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--){
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
4 4
1 2
2 3
3 4
4 1
3 3
1 2
2 3
3 1
*/
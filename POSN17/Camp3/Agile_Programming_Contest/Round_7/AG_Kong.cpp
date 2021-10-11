/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Topological Sort
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
    
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int deg[MaxN];

vector <int> g[MaxN];
queue <int> qu;

vector <pair <int, int>> leaves;
vector <pair <int, int>> nearCycle;

void solve() {
    while(!qu.empty())
        qu.pop();
    leaves.clear();
    nearCycle.clear();
    memset(deg, 0, sizeof deg);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        g[i].clear();
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) {
            deg[i]--;
            qu.push(i);
        }
    }
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for(int x : g[u]) {
            if(!deg[x])
                continue;
            deg[x]--;
            leaves.emplace_back(minmax(x, u));
            if(deg[x] == 1) {
                deg[x]--;
                qu.push(x);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!deg[i])
            continue;
        for(int x : g[i]) {
            if(deg[x])
                continue;
            nearCycle.emplace_back(minmax(i, x));
        }
    }
    if(nearCycle.size()) {
        sort(nearCycle.begin(), nearCycle.end());
        cout << (int)nearCycle.size() << "\n";
        for(auto x : nearCycle) {
            cout << x.first << " " << x.second << "\n";
        }
        return ;
    }
    else {
        sort(leaves.begin(), leaves.end());
        cout << (int)leaves.size() << "\n";
        for(auto x : leaves) {
            cout << x.first << " " << x.second << "\n";
        }
    }
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
2
8 8
1 2
1 3
2 3
3 4
1 5
1 6
6 7
6 8
7 6
1 2
1 3
2 3
5 4
5 6
7 6
*/
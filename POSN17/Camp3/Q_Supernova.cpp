/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Kahn's Algorithm
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
    int u;
    i64 w;
    int idx;
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int deg[N];

i64 sumComponent[N];

i64 edgeValue[N];

vector <GRAPH> g[N];

queue <int> bfs;

void solve() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back({v, 1, i});
        g[v].push_back({u, 1, i});
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        sumComponent[i] = 1;
        if(deg[i] == 1) {
            bfs.push(i);
            deg[i]--;
        }
    }
    while(!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();
        for(auto x : g[u]) {
            if(!deg[x.u])
                continue;
            sumComponent[x.u] += sumComponent[u];
            deg[x.u]--;
            edgeValue[x.idx] = (i64)(sumComponent[u] * (n - sumComponent[u]));
            if(deg[x.u] == 1) {
                deg[x.u]--;
                bfs.push(x.u);
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        cout << edgeValue[i] << " ";
    }
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
6 6
1 2
1 3
1 4
2 3
2 5
3 6
*/
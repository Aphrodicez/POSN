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
    int u, w, state;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int dis[2][N];

vector <GRAPH> g[N];
priority_queue <GRAPH> dijk;

void TESTCASE() {
    
}

void solve() {
    int n, m;
    cin >> n >> m;
    int st, en;
    cin >> st >> en;
    int u, v, w;
    int sum = 0;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        sum += w;
    }
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < n; i++) {
            dis[k][i] = 1e9;    
        }
    }
    dis[0][st] = 0;
    dijk.push({st, 0, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        int state = dijk.top().state;
        dijk.pop();
        if(u == en) {
            cout << sum - w << "\n";
            return ;
        }
        for(auto x : g[u]) {
            int nextw = dis[state][u] + x.w;
            if(dis[state][x.u] > nextw) {
                dis[state][x.u] = nextw;
                dijk.push({x.u, dis[state][x.u], state});
            }
            if(!state) {
                int nextw = dis[state][u];            
                if(dis[state + 1][x.u] > nextw) {
                    dis[state + 1][x.u] = nextw;
                    dijk.push({x.u, dis[state + 1][x.u], state + 1});
                }
            }
        }
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
4 4
0 3
0 1 2
1 3 2
0 2 4
2 3 5

5 4
0 4
0 1 1
0 2 1
2 4 3
4 3 2
*/
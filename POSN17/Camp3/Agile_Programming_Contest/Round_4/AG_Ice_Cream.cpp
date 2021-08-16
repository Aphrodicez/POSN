/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dijkstra's Kth State
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
    int state;
    int eatenNode;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 8e4 + 10;
const int M = 2e5 + 10;
const int K = 10;

i64 dis[K + 1][N];

bool haveIceCream[N];

vector <GRAPH> g[N];

priority_queue <GRAPH> dijk;

void TESTCASE() {
    
}

void solve() {
    int n, m, p, k;
    cin >> n >> m >> p >> k;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for(int state = 0; state <= K; state++) {
        for(int i = 1; i <= n; i++) {
            dis[state][i] = 2e18;
        }
    }
    for(int i = 1; i <= p; i++) {
        cin >> u;
        haveIceCream[u] = true;
    }
    int st = 1;
    dis[0][st] = 0;
    dijk.push({st, 0});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        i64 w = dijk.top().w;
        int state = dijk.top().state;
        int eatenNode = dijk.top().eatenNode;
        dijk.pop();
        if(u == n) {
            cout << w << "\n";
            break;
        }
        for(auto x : g[u]) {
            i64 nextw = dis[state][u] + x.w / (1 << state);
            if(dis[state][x.u] > nextw) {
                dis[state][x.u] = nextw;
                dijk.push({x.u, dis[state][x.u], state, eatenNode});
            }
            if(state == k || !haveIceCream[u] || u == eatenNode)
                continue;
            nextw = dis[state][u] + x.w / (1 << (state + 1));
            if(dis[state + 1][x.u] > nextw) {
                dis[state + 1][x.u] = nextw;
                dijk.push({x.u, dis[state + 1][x.u], state + 1, u});
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
9 9 1 1
1 2 256
2 3 256
3 4 256
4 9 256
1 5 256
5 6 256
6 7 256
7 8 256
8 9 256
5
9 9 2 2
1 2 256
2 3 256
3 4 256
4 9 256
1 5 256
5 6 256
6 7 256
7 8 256
8 9 256
5 7
*/
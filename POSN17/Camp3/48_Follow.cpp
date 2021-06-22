/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: Rejected
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
    int u, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

int entry[N], dis[N];

priority_queue <GRAPH> dijk;

void solve() {
    while(!dijk.empty())
        dijk.pop();
    memset(entry, -1, sizeof entry);
    vector <int> peattRoute;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dis[i] = 1e9;
        g[i].clear();
    }
    int st, en, startTime, peattNode;
    cin >> st >> en >> startTime >> peattNode;
    int u, v, w;
    for(int i = 1; i <= peattNode; i++) {
        cin >> u;
        peattRoute.push_back(u);
    }
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijk.push({peattRoute[0], 0});
    int i = 0;
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        dijk.pop();
        if(i == peattRoute.size() - 1) {
            entry[u] = w;
            break;
        }
        for(auto x: g[u]) {
            if(x.u != peattRoute[i + 1])
                continue;
            entry[u] = w;
            //cout << "PEATT" << u << " " << x.u << " " << entry[u] << "\n";
            dijk.push({x.u, w + x.w});
            i++;
            break;
        }
    }
    dis[st] = startTime;
    dijk.push({st, startTime});
    while(!dijk.empty()) {
        int u = dijk.top().u;
        int w = dijk.top().w;
        dijk.pop();
        /*if(u == en) {
            cout << w - startTime << "\n";
            return ;
        }*/
        for(auto x: g[u]) {
            int nextw = w + x.w;
            if(entry[u] != -1 && entry[x.u] != -1) {
                int nowentry = min(entry[u], entry[x.u]);
                int nextentry = max(entry[u], entry[x.u]);
                if(w >= nowentry && w < nextentry) {
                    nextw = nextentry + x.w;
                }
            }
            if(dis[x.u] <= nextw)
                continue;
            dis[x.u] = nextw;
            dijk.push({x.u, nextw});
        }
    }
    cout << dis[en] - startTime << "\n";
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
2
6 5
1 6 20 4
5 3 2 4
1 2 2
2 3 8
2 4 3
3 5 15
3 6 10
8 9
1 5 5 5
1 2 3 4 5
1 2 8
2 3 10
2 7 4
3 4 23
3 6 5
4 8 4
4 5 5
6 8 3
6 7 40
*/
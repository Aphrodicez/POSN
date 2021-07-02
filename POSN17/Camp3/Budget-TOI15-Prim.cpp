/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Minimum Spanning Tree [Prim] + Greedy Algorithm + Dynamic Programming + Binary Search
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
    int u;
    i64 w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int N = 3e3 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

vector <pair <int, int>> cost;

priority_queue <GRAPH> pq;

bool visited[N];

void solve() {
    memset(visited, false, sizeof (visited));
    int n, m;
    cin >> n >> m;
    int u, v, state;
    i64 w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w >> state;
        if(state)
            w = 0;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int q;
    cin >> q;
    while(q--) {
        i64 w, pi;
        cin >> w >> pi;
        cost.push_back({w, pi});
    }
    sort(cost.begin(), cost.end());
    for(int i = cost.size() - 1; i >= 1; i--) {
        cost[i - 1].second = min(cost[i].second, cost[i - 1].second);
    }
    i64 ans = 0;
    u = 0;
    pq.push({u, 0});
    while(!pq.empty()) {
        int u = pq.top().u;
        i64 w = pq.top().w;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;        
        for(auto x: g[u]) {
            if(visited[x.u])
                continue;
            pq.push({x.u, x.w});
        }
        if(!w)
            continue;
        int l = 0, r = cost.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(cost[mid].first < w)
                l = mid + 1;
            else
                r = mid;
        }
        ans += cost[l].second;

    }
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
6 8
0 1 19 0
1 2 50 1
1 3 5 0
2 3 18 0
0 4 32 0
3 4 22 0
2 5 70 0
4 5 20 1
8
5 60
50 200
75 350
20 100
40 145
15 50
35 150
8 60
*/
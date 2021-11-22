/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Kahn Algorithm + 2 Degenerate Graph + Dijkstra's Algorithm + Bitmasking
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    int u, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

struct COMPRESSED_GRAPH {
    int u, w, mask;
    bool operator < (const COMPRESSED_GRAPH &o) const {
        return w > o.w;
    }
};

vector <GRAPH> g[MaxN];
vector <COMPRESSED_GRAPH> compressed_g[7];

bitset <MaxN> visited;
int deg[MaxN];
queue <int> qu;

int node[MaxN];
map <vector <int>, int> edge;

int dis[1 << 10][7];
priority_queue <COMPRESSED_GRAPH> pq;

int n, m;
int sz_n = 0, sz_edge = 0;
int ans = 0;

void kahn() {
    for(int i = 1; i <= n - 1; i++) {
        if(deg[i] == 1)
            qu.push(i);
    }
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        visited[u] = true;
        for(auto x : g[u]) {
            if(visited[x.u])
                continue;
            ans += x.w * 2;
            if(--deg[x.u] == 1 && x.u) {
                qu.push(x.u);
            }
        }
    }
}

void dijkstra() {
    memset(dis, 127, sizeof dis);
    dis[0][1] = 0;
    pq.push({1, 0, 0});
    while(!pq.empty()) {
        int u = pq.top().u;
        int w = pq.top().w;
        int mask = pq.top().mask;
        pq.pop();
        if(u == 1 && mask == (1 << sz_edge) - 1) {
            ans += dis[mask][u];
            printf("%d\n", ans);
            return ;
        }
        for(auto x : compressed_g[u]) {
            int nextw = w + x.w;
            int nextmask = mask | (1 << x.mask);
            if(dis[nextmask][x.u] <= nextw)
                continue;
            dis[nextmask][x.u] = nextw;
            pq.push({x.u, nextw, nextmask});
        }
    }
}

void compress() {
    node[0] = ++sz_n;
    for(int i = 1; i <= n - 1; i++) {
        if(deg[i] >= 3) {
            node[i] = ++sz_n;
        }
    }
    vector <int> path;
    for(int i = 0; i <= n - 1; i++) {
        if(!node[i])
            continue;
        int cycle = 0;
        for(auto x : g[i]) {
            if(visited[x.u])
                continue;
            path.clear();
            path.emplace_back(i);
            int parent = i, u = x.u, sum = x.w;
            path.emplace_back(u);
            while(!node[u]) {
                for(auto y : g[u]) {
                    if(visited[y.u] || y.u == parent)   
                        continue;
                    sum += y.w;
                    parent = u;
                    u = y.u;
                    break;
                }
                path.emplace_back(u);
            }
            if(i == u) {
                cycle += sum;
                continue;
            }
            int st = node[i], en = node[u];
            if(st > en)
                reverse(path.begin(), path.end());
            if(edge.find(path) == edge.end()) {
                compressed_g[st].push_back({en, sum, sz_edge});
                compressed_g[en].push_back({st, sum, sz_edge});
                edge.insert(make_pair(path, ++sz_edge));
            }
        }
        ans += cycle / 2;
    }
}

void solve() {
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        deg[u]++, deg[v]++;
    }
    kahn();
    compress();
    dijkstra();
}

int main() {
    int q = 1;

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
9 9
0 3 1
3 5 2
5 4 4
4 2 3
2 1 4
1 5 6
6 3 7
6 7 5
6 8 6

7 6
0 1 10
0 2 2
1 2 1
2 3 8
3 4 10
4 5 5
3 1 5
*/
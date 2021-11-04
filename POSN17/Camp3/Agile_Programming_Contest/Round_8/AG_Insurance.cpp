/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Minimum Spanning Tree + Binary Search
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
    int u, v;
    long long w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int a[MaxN];
int p[MaxN];
priority_queue <GRAPH> pq;

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

unordered_map <int, long long> component[MaxN];

long long ans[MaxN];
long long edge[MaxN];

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        cin >> a[i];
        component[i][a[i]] = 1;
    }
    int u, v;
    long long w;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        pq.push({u, v, w});
    }
    int cnt = 0;
    while(!pq.empty()) {
        int u = pq.top().u;
        int v = pq.top().v;
        long long w = pq.top().w;
        pq.pop();
        edge[++cnt] = w;
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            continue;
        int parent = ru;
        int child = rv;
        if((int)component[child].size() > (int)component[parent].size())
            swap(parent, child);
        long long sum = 0;
        for(auto y : component[parent]) {
            sum += y.second;
        }
        for(auto x : component[child]) {
            ans[cnt] += x.second * (sum - component[parent][x.first]) * 2;
        }
        for(auto x : component[child]) {
            component[parent][x.first] += x.second;
        }
        p[child] = parent;
    }
    for(int i = 1; i <= cnt; i++) {
        ans[i] += ans[i - 1];
    }
    while(q--) {
        long long w;
        cin >> w;
        cout << ans[upper_bound(edge + 1, edge + cnt + 1, w) - edge - 1] << "\n";
    }
}

int main() {
    setIO();
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
5 2
1 2 1 2 1
1 2 1
2 3 2
3 4 3
4 5 4
2
3
*/
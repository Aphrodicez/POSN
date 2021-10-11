/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Minimum Spanning Tree
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
    int u, v, w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {

}

priority_queue <GRAPH> pq;

int a[MaxN];
int p[MaxN];

int find_root(int i) {
    if(p[i] == i)
        return i;
    return p[i] = find_root(p[i]);
}

unordered_map <int, long long> mp[MaxN];
long long qs[MaxN];
int c[MaxN], sortedLimit[MaxN];

void solve() {
    int n, q;
    cin >> n >> q;
    int u, v, w;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i;
        mp[i][a[i]] = 1;
    }
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        pq.push({u, v, w});
    }
    for(int i = 1; i <= q; i++) {
        cin >> c[i];
        sortedLimit[i] = c[i];
    }
    sort(sortedLimit + 1, sortedLimit + q + 1);
    while(!pq.empty()) {
        int u = pq.top().u;
        int v = pq.top().v;
        int w = pq.top().w;
        pq.pop();
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            continue;
        int parent = ru;
        int child = rv;
        if(mp[child].size() > mp[parent].size())
            swap(child, parent);
        int idx = lower_bound(sortedLimit + 1, sortedLimit + q + 1, w) - sortedLimit;
        for(auto u : mp[parent]) {
            for(auto v : mp[child]) {
                if(u.first != v.first)
                    qs[idx] += u.second * v.second; 
            }
        }
        for(auto v : mp[child]) {
            mp[parent][v.first] += v.second;
        }
        p[child] = parent;
    }
    for(int i = 1; i <= q; i++) {
        qs[i] += qs[i - 1];
    }
    for(int i = 1; i <= q; i++) {
        cout << 2 * qs[upper_bound(sortedLimit + 1, sortedLimit + q + 1, c[i]) - sortedLimit - 1] << "\n";
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
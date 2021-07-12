/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union + Greedy Algorithm + Binary Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (i64)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const i64 d4i[] = {-1, 0, 1, 0};
const i64 d4j[] = {0, 1, 0, -1};
const i64 d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const i64 d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const i64 N = 5e5 + 10;
const i64 M = 2e5 + 10;

i64 a[N], b[N], pa[N];

struct A {
    i64 componentRoot, val;
    bool operator < (const A &o) const {
        if(componentRoot != o.componentRoot)
            return componentRoot < o.componentRoot;
        return val > o.val;
    }
};

struct B {
    i64 componentRoot, val;
    bool operator < (const B &o) const {
        if(componentRoot != o.componentRoot)
            return componentRoot < o.componentRoot;
        return val < o.val;
    }
};

A increase[N];
B decrease[N];

vector <i64> component, warp;

map <i64, i64> mapp;

i64 find_root(i64 u) {
    if(pa[u] == u)
        return u;
    return pa[u] = find_root(pa[u]);
}

void TESTCASE() {
    i64 w;
    cin >> w;
    i64 idx = lower_bound(all(warp), -1 * w) - warp.begin() - 1;
    i64 ans = component[idx] - w * idx;
    cout << ans << "\n";
}

void solve() {  
    i64 n, m, q;
    cin >> n >> m >> q;
    for(i64 i = 1; i <= n; i++) {
        pa[i] = i;
        cin >> a[i] >> b[i];
    }
    i64 u, v;
    for(i64 i = 1; i <= m; i++) {
        cin >> u >> v;
        i64 ru = find_root(u);
        i64 rv = find_root(v);
        if(ru == rv)
            continue;
        pa[rv] = ru;
    }
    for(i64 i = 1; i <= n; i++) {
        i64 root = find_root(i);
        increase[i] = {root, a[i]};
        decrease[i] = {root, b[i]};
    }
    sort(increase + 1, increase + n + 1);
    sort(decrease + 1, decrease + n + 1);
    i64 componentSum = 0;
    for(i64 i = 1; i <= n; i++) {
        componentSum += max(0ll, increase[i].val - decrease[i].val);        
        if(increase[i].componentRoot != increase[i + 1].componentRoot) {
            component.push_back(componentSum);
            componentSum = 0;
        }
    }
    sort(all(component), greater <i64>());
    warp.push_back(-1e12 - 10);
    for(i64 i = 1; i < component.size(); i++) {
        warp.push_back(-1 * component[i]);
        component[i] += component[i - 1];
    }
    while(q--) {
        TESTCASE();
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
10 8 2
9 7
3 1
2 9
1 1
3 6
2 5
10 1
20 12
10 2
3 1
1 2
2 3
4 5
6 4
6 7
8 9
9 8
8 10
5
9
*/
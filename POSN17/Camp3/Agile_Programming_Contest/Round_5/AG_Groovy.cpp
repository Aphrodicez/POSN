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

struct HEAP {
    int u, v;
    long long w;
    bool operator < (const HEAP &o) const{
        return w > o.w;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {

}

int p[N];

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

priority_queue <HEAP> pq;

void solve() {
    while(!pq.empty())
        pq.pop();
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        p[i] = i;
    int u, v;
    long long w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        pq.push({u, v, w});
    }
    long long ans = 0;
    while(!pq.empty()) {
        int u = pq.top().u;
        int v = pq.top().v;
        long long w = pq.top().w;
        pq.pop();
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            continue;
        k++;
        p[rv] = ru;
        if(k > n - 1)
            continue;
        ans += w;
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
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
1
5 6 1
1 2 5
2 3 4
2 5 2
3 4 10
3 5 6
4 5 3
*/

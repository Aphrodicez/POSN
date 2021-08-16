/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union + Binary Search
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
    
};

const int N = 1e5 + 10;
const int M = 1e6 + 10;

void TESTCASE() {
    
}

int a[N], p[N], ans[M];

map <int, int> mapp;

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        cin >> a[i];
        mapp[a[i]]++;
        mx = max(mx, a[i]);
    }
    int u, v;
    ans[0] = mapp.begin()->first;
    for(int i = 1; i <= k; i++) {
        cin >> u >> v;
        int ru = find_root(u);
        int rv = find_root(v);
        ans[i] = mapp.begin()->first;
        int parent = ru, child = rv;
        if(parent == child)
            continue;
        if(a[rv] > a[ru])
            swap(parent, child);
        p[child] = parent;
        mapp[a[child]]--;
        if(!mapp[a[child]])
            mapp.erase(a[child]);
        ans[i] = mapp.begin()->first;
    }
    while(q--) {
        int idx;
        cin >> idx;
        int lb = lower_bound(ans, ans + k + 1, idx) - ans;
        cout << (lb > k ? -1 : lb) << "\n";
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
6 5 4
1 2 3 4 5 6
1 2
3 1
2 6
4 5
5 6
1
3
7
4

3 3 4
1 2 3
1 2
2 3
1 3
1
2
3
4

*/
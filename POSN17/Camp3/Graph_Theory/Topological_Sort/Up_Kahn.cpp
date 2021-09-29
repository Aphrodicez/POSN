/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Topological Sort
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
    
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int deg[MaxN];

vector <int> g[MaxN];

priority_queue <int, vector <int>, greater <int>> pq;

vector <int> ans;

void solve() {
    ans.clear();
    memset(deg, 0, sizeof deg);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        g[i].clear();
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!deg[i])
            pq.push(i);
    }
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for(int x : g[u]) {
            deg[x]--;
            if(!deg[x])
                pq.push(x);
        }
    }
    if((int)ans.size() != n) {
        cout << "No";
        return ;
    }
    cout << "Yes" << " ";
    for(int x : ans) {
        cout << x << " ";
    }
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
    for(int i = 1; i <= q; i++) {
        solve();
        cout << "\n";
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
2
5 5
1 2
1 3
2 4
3 5
4 5
5 6
1 2
1 3
2 4
3 5
4 5
4 1
*/
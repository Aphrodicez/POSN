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

const int MaxN = 5e4 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[MaxN];

int deg[MaxN];

priority_queue <int, vector <int>, greater <int>> pq;

vector <int> ans;

void solve() {
    ans.clear();
    memset(deg, 0, sizeof deg);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
    }
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> v >> u;
        g[u].emplace_back(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!deg[i]) {
            pq.push(i);
        }
    }
    int cnt = 0;
    int swapPos = -1;
    while(!pq.empty()) {
        cnt++;
        if(pq.size() > 1)
            swapPos = cnt - 1; 
        int u = pq.top();
        ans.emplace_back(u);
        pq.pop();
        for(int x : g[u]) {
            deg[x]--;
            if(!deg[x]) {
                pq.push(x);
            }
        }
    }
    if((int)ans.size() != n) {
        cout << "Never";
        return;
    }
    if(swapPos != -1) {
        swap(ans[swapPos], ans[swapPos + 1]);
        cout << "Different" << " ";
    }
    else {
        cout << "Same" << " ";
    }
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
3
4 4
2 1
3 1
4 2
4 3
2 2
1 2
2 1
2 1
1 2
*/
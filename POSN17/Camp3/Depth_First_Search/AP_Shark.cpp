/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Depth First Search
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

const int MaxN = 1e3 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int a[MaxN];

vector <int> g[MaxN];

int mark[MaxN];

int root, sum = 0;

void dfs(int u) {
    mark[u] = root;
    sum += a[u];
    for(int x : g[u]) {
        if(mark[x] == root)
            continue;
        dfs(x);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    int ans, mx = -1;
    for(int i = 1; i <= n; i++) {
        sum = 0;
        root = i;
        dfs(i);
        if(sum > mx) {
            ans = i;
            mx = sum;
        }
    }
    cout << ans << " " << mx << "\n";
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
5 6
7 2 3 9 4
1 3
2 5
4 1
3 5
4 5
2 1
*/
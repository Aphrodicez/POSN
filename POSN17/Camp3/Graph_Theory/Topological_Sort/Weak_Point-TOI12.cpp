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

const int MaxN = 5e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

queue <int> topo;
vector <int> g[MaxN];

int deg[MaxN];
int dp[MaxN];

int n, st;

void rootOutsideCycle() {
    int ansidx = n, ans = -1;
    for(int x : g[st]) {
        int sum = dp[x];
        if(dp[x] > dp[st]) {
            sum = n - (dp[st] + 1) - 1;
        }
        if(sum > ans) {
            ansidx = x;
        }
        else if(sum == ans) {
            ansidx = min(ansidx, x);
        }
        ans = max(ans, sum);
    }
    cout << ansidx << "\n";
    cout << ans << "\n";
}

void rootInsideCycle() {
    int ansidx = n, ans = -1;
    for(int i = 1; i <= n; i++) {
        if(i == st)
            continue;
        int sum = dp[i];
        if(sum > ans) {
            ansidx = i;
        }
        else if(sum == ans) {
            ansidx = min(i, ansidx);
        }
        ans = max(ans, sum);
    }
    cout << ansidx << "\n";
    cout << ans << "\n";
}

void solve() {
    cin >> n >> st;
    int u, v;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) {
            deg[i]--;
            topo.push(i);
        }
    }
    while(!topo.empty()) {
        int u = topo.front();
        topo.pop();
        for(auto x : g[u]) { 
            if(deg[x] < 1)
                continue;
            deg[x]--;           
            dp[x] += dp[u] + 1;
            if(deg[x] == 1) {
                deg[x]--;
                topo.push(x);
            }
        }
    }
    if(!deg[st]) {
        rootOutsideCycle();
    }
    else {
        rootInsideCycle();
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
12 1
1 2
1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12

12 12
1 2
1 6
1 7
1 12
6 8
6 9
2 3
2 10
10 11
3 4
4 5
5 12

4 1
3 2
1 2
1 4
3 4
*/
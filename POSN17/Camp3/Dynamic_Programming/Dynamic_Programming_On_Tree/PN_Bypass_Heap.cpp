/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
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
    int idx;
    i64 val;
    bool operator < (const GRAPH &o) const {
        return val > o.val;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[N];

i64 dp[N];

GRAPH FirstSubTree[N], SecondSubTree[N];

i64 ans = 0;

int n;

void dfsSumSubTree(int u, int p) {
    dp[u] = 1;
    priority_queue <GRAPH> pq;
    pq.push({0, 0});
    for(int x : g[u]) {
        if(x == p)
            continue;
        dfsSumSubTree(x, u);
        dp[u] += dp[x];
        pq.push({x, dp[x]});
        if(pq.size() > 2)
            pq.pop();
    }
    SecondSubTree[u] = pq.top();
    pq.pop();
    FirstSubTree[u] = pq.top();
    pq.pop();
}

void dfsByPass(int u, int p) {
    priority_queue <GRAPH> pq;
    if(u != p) {
        dp[p] = n - dp[u];
        pq.push({p, dp[p]});
    }
    pq.push(FirstSubTree[u]);
    pq.push(SecondSubTree[u]);
    if(pq.size() > 2)
        pq.pop();
    SecondSubTree[u] = pq.top();
    pq.pop();
    FirstSubTree[u] = pq.top();
    pq.pop();
    for(int x : g[u]) {
        if(x == p)
            continue;
        if(FirstSubTree[u].idx != x)
            ans = max(ans, FirstSubTree[u].val * FirstSubTree[x].val);
        else
            ans = max({ans, SecondSubTree[u].val * FirstSubTree[x].val});
        dfsByPass(x, u);
    }
}

void solve() {
    ans = 0;
    memset(FirstSubTree, 0, sizeof (FirstSubTree));
    memset(SecondSubTree, 0, sizeof (SecondSubTree));
    memset(dp, 0, sizeof (dp));
    cin >> n;
    for(int i = 1; i <= n; i++)
        g[i].clear();
    int u, v;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsSumSubTree(1, 1);
    dfsByPass(1, 1);
    cout << ans << "\n";
}

int main() {
    setIO();
    int q;
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
2
6
1 3
2 3
3 4
4 5
5 6
9
1 2 
2 3
3 4
4 5
5 6
6 7
7 8
8 9
*/
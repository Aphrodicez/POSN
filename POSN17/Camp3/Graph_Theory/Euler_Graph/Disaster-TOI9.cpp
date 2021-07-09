/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Euler Graph [DFS] + Greedy Algorithm
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
    int u, idx;
    bool operator < (const GRAPH &o) const {
        return u < o.u;
    }
};

const int N = 3e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <GRAPH> g[N];

int deg[N];

bool visited[N];

vector <char> ans;

int n;

void dfs(int u) {
    if(ans.size() == n + 1) {
        for(char x: ans) {
            cout << x << " ";
        }
        exit(0);
    }
    for(auto x : g[u]) {
        if(visited[x.idx])
            continue;
        visited[x.idx] = true;
        ans.push_back(char(x.u + 'A' - 1));
        dfs(x.u);
        visited[x.idx] = false;
        ans.pop_back();
    }
}

void solve() {
    cin >> n;
    char uchr, vchr;
    int u, v;
    for(int i = 1; i <= n; i++) {
        cin >> uchr >> vchr;
        u = uchr - 'A' + 1;
        v = vchr - 'A' + 1;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        deg[u]++;
        deg[v]++;
    }
    int st = -1, mnstart = -1;
    for(int i = 26; i >= 1; i--) {
        sort(g[i].begin(), g[i].end());
        if(deg[i] % 2)
            st = i;
        if(deg[i])
            mnstart = i;
    }
    if(st == -1)
        st = mnstart;
    ans.push_back(char(st + 'A' - 1));
    dfs(st);
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
6
AB
AE
BD
BC
CE
DE

4
AB
DA
BC
DC
*/
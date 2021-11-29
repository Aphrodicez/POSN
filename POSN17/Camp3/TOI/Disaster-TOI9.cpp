/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Euler Path
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 3e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    int u, i;
    bool operator < (const GRAPH &o) const {
        return u < o.u;
    }
};

char s[2];

vector <GRAPH> g[26];

int deg[26];

bitset <MaxN> visited;

vector <int> ans;

int n;

void dfs(int u, int state) {
    if(state == n) {
        for(int x : ans) {
            printf("%c ", x + 'A');
        }
        exit(0);
    }
    for(auto x : g[u]) {
        if(visited[x.i])
            continue;
        visited[x.i] = true;
        ans.push_back(x.u);
        dfs(x.u, state + 1);
        visited[x.i] = false;
        ans.pop_back();
    }
}

void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf(" %s", s);
        int u = s[0] - 'A';
        int v = s[1] - 'A';
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        deg[u]++;
        deg[v]++;
    }
    int st = -1;
    int minst = 26;
    for(int i = 25; i >= 0; i--) {
        if(deg[i] % 2)
            st = i;
        if(deg[i])
            minst = i;
        sort(g[i].begin(), g[i].end());
    }
    if(st == -1)
        st = minst;
    ans.emplace_back(st);
    dfs(st, 0);
}

int main() {
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
6
AB
AE
BD
BC
CE
DE
*/
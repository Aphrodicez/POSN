/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union [SAC] + Quick XOR + Math + DFS 
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
    int u, w;
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

vector <GRAPH> g[N];

i64 qxor[N];

void dfs(int u, int pa, i64 w) {
    qxor[u] = w;
    for(auto x : g[u]) {
        if(x.u == pa)
            continue;
        dfs(x.u, u, w ^ x.w);
    }
}

int pa[N];

int find_root(int u) {
    if(pa[u] == u)
        return u;
    return pa[u] = find_root(pa[u]);
}

unordered_map <i64, i64> mapp[N];

pair <int, int> edge[N];

void TESTCASE() {

}

void solve() {
    int n;
    cin >> n;
    int u, v, w;
    for(int i = 1; i <= n; i++)
        pa[i] = i;
    for(int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edge[i] = make_pair(u, v);
    }
    stack <pair <int, int>> cut;
    int idx;
    for(int i = 1; i <= n - 1; i++) {
        cin >> idx;
        cut.push(edge[idx]);
    }
    dfs(1, 1, 0);
    for(int i = 1; i <= n; i++) {
        mapp[i][qxor[i]] = 1;
    }
    vector <i64> ans;
    i64 sum = 0;
    ans.push_back(sum);
    while(!cut.empty()) {
        int u = cut.top().first;
        int v = cut.top().second;
        cut.pop();
        int ru = find_root(u);
        int rv = find_root(v);
        int big = ru;
        int small = rv;
        if(mapp[ru].size() < mapp[rv].size()) {
            big = rv;
            small = ru;
        }
        for(auto x : mapp[small]) {
            int state = x.first;
            sum += mapp[big][state] * mapp[small][state];
            mapp[big][state] += mapp[small][state];
            pa[small] = big;
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) {
        cout << x << "\n";
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
4
1 2 4
2 3 4
2 4 2
3 1 2
*/
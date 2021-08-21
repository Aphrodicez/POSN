/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search + Kahn's Algorithm
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

const int N = 5e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[N];

bool visited[N];

int p[N], deg[N];

queue <int> bfs;

void solve() {
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; i++)
        p[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector <pair <int, int>> ans;
    vector <int> component;
    for(int i = 1; i <= n; i++) {
        if(visited[i])
            continue;
        component.clear();
        bool isTree = true;
        bfs.push(i);
        visited[i] = true;
        while(!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            component.push_back(u);
            for(auto x : g[u]) {
                if(x == p[u])
                    continue;
                if(visited[x]) {
                    isTree = false;
                    continue;
                }
                visited[x] = true;
                p[x] = u;
                bfs.push(x);
            }
        }
        for(int x : component) {
            if(deg[x] == 1) {
                deg[x]--;
                bfs.push(x);
            }
        }
        if(isTree) {
            while(!bfs.empty()) {
                int u = bfs.front();
                bfs.pop();
                for(auto x : g[u]) {
                    ans.push_back(make_pair(u, x));
                }
            }
        }
        else {
            while(!bfs.empty()) {
                int u = bfs.front();
                bfs.pop();
                for(int x : g[u]) {
                    deg[x]--;
                    if(deg[x] == 1) {
                        deg[x]--;
                        bfs.push(x);
                    }
                }
            }
            for(int u : component) {
                if(deg[u] > 0) {
                    for(int x : g[u]) {
                        if(deg[x] < 1) {
                            ans.push_back(make_pair(u, x));
                        }
                    }
                }
            }
        }
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(pair <int, int> x : ans) {
        cout << x.first << " " << x.second << "\n";
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
6 5
1 2
1 3
2 3
4 5
5 6

8 8
1 2
1 3
2 3
3 4
1 5
1 6
6 7
6 8
*/
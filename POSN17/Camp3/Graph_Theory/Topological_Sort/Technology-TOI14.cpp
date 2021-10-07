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

const int MaxN = 1e5 + 10;
const int MaxK = 1e4 + 10;

void TESTCASE() {
    
}

vector <int> g[MaxN], level[MaxK];

bool visited[MaxN], visitedCycle[MaxN];
bool isCycle = false;

int n, k, t;

void dfs(int u, int p) {
    if(isCycle || visitedCycle[u]) {
        isCycle = true;
        return ;
    }
    visitedCycle[u] = true;
    for(int x : g[u]) {
        if(visited[x])
            continue;
        dfs(x, u);
        if(isCycle)
            return ;
    }
    visited[u] = true;
    t--;
}

void solve() {
    cin >> n >> k >> t;
    for(int i = 1; i <= n; i++) {
        int lvl;
        cin >> lvl;
        level[lvl].emplace_back(i);
        int q;
        cin >> q;
        int u;
        for(int j = 1; j <= q; j++) {
            cin >> u;
            g[i].emplace_back(u);
        }
    }
    int ans = 0;
    for(ans = 1; ans <= k; ans++) {
        for(int u : level[ans]) {
            if(visited[u])
                continue;
            dfs(u, u);
            if(t < 0 || isCycle)
                break;
        }
        if(t <= 0 || isCycle) {
            break;
        }
    }
    if(t < 0 || isCycle)
        ans--;
    cout << (ans ? ans : -1) << "\n";
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
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1

7 4 7
3 1 2
1 0
4 2 7 1
1 1 5
2 1 2
3 1 4
4 1 6

3 2 3
1 2 2 3
2 2 1 3
2 2 1 2
*/
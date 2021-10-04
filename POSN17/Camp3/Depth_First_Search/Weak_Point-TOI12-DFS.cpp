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

struct GRAPH {
    
};

const int MaxN = 5e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[MaxN];
bool visited[MaxN];
stack <pair <int, int>> dfs;
int dp[MaxN];
bool isCycle[MaxN];

void solve() {
    int n, st;
    cin >> n >> st;
    int u, v;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    bool cycle = false;
    dfs.push(make_pair(st, st));
    while(!dfs.empty()) {
        int u = dfs.top().first;
        int p = dfs.top().second;
        if(visited[u]) {
            if(!isCycle[u])
                dp[p] += dp[u] + 1;
            else
                isCycle[p] = true;
            dfs.pop();
            continue;
        }
        visited[u] = true;
        for(int x : g[u]) {
            if(x == p)
                continue;
            if(x == st) {
                cycle = true;
            }
            if(visited[x]) {
                isCycle[u] = true;
                continue;
            }
            dfs.push(make_pair(x, u));
        }
    }
    int idxInCycle = n, ansInCycle = -1, idxOutCycle = n, ansOutCycle = -1;
    if(cycle) {
        for(int i = 1; i <= n; i++) {
            if(i == st)
                continue;
            int sum = dp[i];
            if(sum > ansInCycle) {
                idxInCycle = i;
            }
            else if(sum == ansInCycle) {
                idxInCycle = min(idxInCycle, i);
            }
            ansInCycle = max(ansInCycle, sum);
        }
        cout << idxInCycle << "\n";
        cout << ansInCycle << "\n";
    }
    else {
        for(int x : g[st]) {
            int sum = dp[x];
            if(isCycle[x]) {
                sum = n - (dp[st] + 1) - 1;
            }
            if(sum > ansOutCycle) {
                idxOutCycle = x;
            }
            else if(sum == ansOutCycle) {
                idxOutCycle = min(idxOutCycle, x);
            }
            ansOutCycle = max(ansOutCycle, sum);
        }
        cout << idxOutCycle << "\n";
        cout << ansOutCycle << "\n";
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
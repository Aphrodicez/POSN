/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Cycle Detection + Dynamic Programming On Tree
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
    int u;
    long long w;
    bool operator < (const GRAPH &o) const {
        return w > o.w;
    }
};

const int MaxN = 5e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int g[MaxN];
long long a[MaxN];
vector <int> reverseEdge[MaxN];

bool visited[MaxN];

queue <int> iterateCycle;

vector <long long> components;

long long dfs(int u, int p) {
    visited[u] = true;
    long long mx = 0;
    for(int x : reverseEdge[u]) {
        if(x == p)
            continue;
        if(visited[x])
            continue;
        long long res = dfs(x, u);
        if(res > mx) {
            if(mx) {
                components.push_back(mx);
            }
            mx = res;
        }
        else {
            if(res)
                components.push_back(res);
        }
    }
    return a[u] + mx;
}

void reset(int n) {
    while(!iterateCycle.empty())
        iterateCycle.pop();
    memset(visited, false, sizeof visited);
    components.clear();
    for(int i = 1; i <= n; i++) {
        reverseEdge[i].clear();
    }
}

void solve() {
    int n;
    cin >> n;
    reset(n);
    for(int i = 1; i <= n; i++) {
        cin >> g[i] >> a[i];
        reverseEdge[g[i]].push_back(i);
    }
    int k;
    cin >> k;
    k++;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            int root;
            long long sum = 0;
            iterateCycle.push(i);
            while(!iterateCycle.empty()) {
                int u = iterateCycle.front();
                iterateCycle.pop();
                sum += a[u];
                int x = g[u];
                visited[u] = true;
                if(visited[x]) {
                    root = x;
                    break;
                }
                iterateCycle.push(x);
            }
            if(root != i)
                iterateCycle.push(i);
            while(!iterateCycle.empty()) {
                int u = iterateCycle.front();
                iterateCycle.pop();
                visited[u] = false;
                sum -= a[u];
                int x = g[u];
                if(x == root)
                    break;
                iterateCycle.push(x);
            }
            long long mx = 0;
            iterateCycle.push(root);
            while(!iterateCycle.empty()) {
                int u = iterateCycle.front();
                iterateCycle.pop();
                int x = g[u];
                long res = dfs(u, u) - a[u];
                if(res >= mx) {
                    if(mx) {
                        components.push_back(mx);
                    }
                    mx = res;
                }
                else {
                    if(res)
                        components.push_back(res);
                }
                if(x == root)
                    break;
                iterateCycle.push(x);
            }
            components.push_back(sum + mx);
        }
    }
    sort(components.begin(), components.end(), greater <long long>());
    long long ans = 0;
    for(int i = 0; i < min(k, (int)components.size()); i++) {
        ans += components[i];
    }
    cout << ans;
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
2
5
2 5
4 7
4 6
5 3
2 9
0
5
2 5
4 7
4 6
5 3
2 9
1
*/
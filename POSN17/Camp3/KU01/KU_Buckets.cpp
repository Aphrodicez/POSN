/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

struct BUCKET {
    int x, i;
    bool operator < (const BUCKET &o) const {
        return x < o.x;
    }
};

int need[310];

vector <int> g[310];

void dfs(int u, int p) {
    for(int x : g[u]) {
        dfs(x, u);
        need[u] += need[x];
    }
}

int dfsAns(int u, int p) {
    for(int x : g[u]) {
        if(need[x] == need[u]) {
            return dfsAns(x, u);
        }
    }
    return u;
}

void TESTCASE() {
    
}

void solve() {
    memset(need, 0, sizeof need);
    int n, m;
    scanf("%d %d", &n, &m);
    vector <BUCKET> eventPoint;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        int l, r;
        scanf("%d %d", &l, &r);
        eventPoint.push_back({l, i});
        eventPoint.push_back({r, i});
    }
    sort(eventPoint.begin(), eventPoint.end());
    stack <int> st;
    vector <int> roots;
    for(int i = 0; i < (int)eventPoint.size(); i++) {
        int now = eventPoint[i].i;
        if(st.empty()) {
            roots.push_back(now);
            st.push(now);
            continue;
        }
        if(st.top() == now) {
            st.pop();
            continue;
        }
        g[st.top()].push_back(now);
        st.push(now);
    }
    for(int i = 1; i <= m; i++) {
        int u;
        scanf("%d", &u);
        need[u] = 1;
    }
    for(int i = 0; i < (int)roots.size(); i++) {
        int u = roots[i];
        dfs(u, u);
    }
    vector <int> ans;
    for(int i = 0; i < (int)roots.size(); i++) {
        int u = roots[i];        
        if(!need[u])
            continue;
        ans.push_back(dfsAns(u, u));
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i = 0; i < (int)ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main() {
    int q = 1;
    scanf("%d", &q);
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
3
7 3
1 5
2 3
6 16
7 10
11 15
13 14
17 20
2 4 6
7 3
1 10
2 9
3 8
4 7
5 6
11 14
12 13
3 5 6
6 3
1 20
2 10
3 4
5 6
7 8
30 40
3 4 5
*/
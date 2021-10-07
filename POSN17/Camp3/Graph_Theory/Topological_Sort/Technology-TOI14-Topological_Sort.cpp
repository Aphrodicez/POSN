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
    int u, lvl;
    bool operator < (const GRAPH &o) const {
        return lvl < o.lvl;
    }
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[MaxN], reverseEdge[MaxN];
queue <int> qu;
priority_queue <GRAPH> pq;
int degIn[MaxN], degOut[MaxN];
bool Acyclic[MaxN];

int lvlArr[MaxN];
bool incompleteLevel[MaxN];

void solve() {
    int n, k, t;
    cin >> n >> k >> t;
    for(int i = 1; i <= n; i++) {
        cin >> lvlArr[i];
        int p;
        cin >> p;
        int u;
        for(int j = 1; j <= p; j++) {
            cin >> u;
            g[u].emplace_back(i);
            reverseEdge[i].emplace_back(u);
            degIn[i]++;
            degOut[u]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!degIn[i]) {
            qu.push(i);
        }
    }
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        Acyclic[u] = true;
        for(int x : g[u]) {
            if(Acyclic[x])
                continue;
            degIn[x]--;
            if(!degIn[x]) {
                qu.push(x);
            }
        }
    }
    int cnt = n;
    for(int i = 1; i <= n; i++) {
        if(!Acyclic[i]) {
            cnt--;
            incompleteLevel[lvlArr[i]] = true;
            continue;
        }
        if(!degOut[i]) {
            pq.push({i, lvlArr[i]});
        }
    }
    while(!pq.empty() && cnt > t) {
        int u = pq.top().u;
        int lvl = pq.top().lvl;
        pq.pop();
        cnt--;
        incompleteLevel[lvl] = true;
        for(int x : reverseEdge[u]) {
            if(!degOut[x])
                continue;
            degOut[x]--;
            if(!degOut[x]) {
                pq.push({x, lvlArr[x]});
            }
        }
    }
    incompleteLevel[k + 1] = true;
    incompleteLevel[0] = incompleteLevel[1];
    for(int i = -1; i <= k; i++) {
        if(incompleteLevel[i + 1]) {
            cout << i << "\n";
            exit(0);
        }
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
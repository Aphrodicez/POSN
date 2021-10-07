/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Topological Sort + Binary Search
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
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <int> g[MaxN], reverseEdge[MaxN];
queue <int> qu;
int degIn[MaxN], degOut[MaxN];
bool Acyclic[MaxN];

int lvlArr[MaxN];
bool visited[MaxN];

int cnt = 0;

void bfs(int st, int t) {
    while(!qu.empty())
        qu.pop();
    visited[st] = true;
    qu.push(st);
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        cnt++;
        for(int x : reverseEdge[u]) {
            if(visited[x])
                continue;
            visited[x] = true;
            qu.push(x);
        }   
    }
}

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
    int lb = 0, rb = k;
    for(int i = 1; i <= n; i++) {
        if(!Acyclic[i]) {
            rb = min(rb, lvlArr[i] - 1);
            continue;
        }
    }
    while(lb < rb) {
        memset(visited, false, sizeof visited);
        int midb = (lb + rb + 1) / 2;
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(!Acyclic[i])
                continue;
            if(visited[i])
                continue;
            if(lvlArr[i] <= midb) {
                bfs(i, t);
            }
        }
        if(cnt > t)
            rb = midb - 1;
        else
            lb = midb;
    }
    cout << (lb ? lb : -1) << "\n";
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

5 2 7
1 0
2 3 5 3 4
1 1 4
1 1 1
1 4 2 3 1 4

*/
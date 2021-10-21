/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bellman Ford's Algorithm
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

struct EDGE {
    int u, v, w;
};

const int N = 1e3 + 10;
const int M = 11e2 + 10;

void TESTCASE() {
    
}

int dis[N], dis2[N];

EDGE e[M];

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    for(int i = m + 1; i <= m + k; i++) {
        cin >> u >> v >> w;
        e[i] = {u, v, -w};
    }
    int st;
    while(q--) {
        for(int i = 1; i <= n; i++) {
            dis[i] = 1e9;
        }
        cin >> st;
        dis[st] = 0;
        for(int j = 1; j <= n - 1; j++) {
            for(int i = 1; i <= m + k; i++) {
                u = e[i].u;
                v = e[i].v;
                w = e[i].w;
                if(dis[u] == 1e9)
                    continue;
                dis[v] = min(dis[v], dis[u] + w);
            }
        }
        memcpy(dis2, dis, sizeof (dis));
        for(int i = 1; i <= m + k; i++) {
            u = e[i].u;
            v = e[i].v;
            w = e[i].w;
            if(dis[u] == 1e9)
                continue;
            dis[v] = min(dis[v], dis[u] + w);
        }
        for(int i = 1; i <= n; i++) {
            cout << ( (dis[i] == dis2[i] && dis[i] != 1e9) ? dis[i] : -1) << " ";
        }
        cout << "\n";
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
10 5 5 5
1 7 8
2 5 1
3 4 7
5 8 4
5 1 11
10 1 6
10 5 3
10 3 1
9 5 10
5 7 2
2
4
6
8
10
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Floyd Warshall's Algorithm
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

const int N = 3e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dis[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dis[i][j] = 1e9;
        }
    }
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w; 
        dis[u][v] = min(dis[u][v], w);
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << (dis[i][j] == 1e9 ? 0 : dis[i][j]) << " ";
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
4 5
1 2 10
2 3 10
1 3 15
4 4 10
4 1 10
*/
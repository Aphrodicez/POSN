/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

const int MaxN = 5e2 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

int dis[MaxN][MaxN], nearestNode[3][MaxN];

vector <int> a;

void solve() {
    a.clear();
    int n, m, K;
    cin >> n >> m >> K;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n + 1; j++) {
            dis[i][j] = 1e9;
        }
        for(int it = 0; it < 3; it++) {
            nearestNode[it][i] = n + 1;
        }
        dis[i][i] = 0;
    }
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    for(int i = 1; i <= K; i++) {
        cin >> u;
        a.push_back(u);
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
            }
        }
    }
    for(int i : a) {
        for(int j : a) {
            if(i == j)
                continue;
            if(dis[i][j] == 1e9)
                continue;
            if(dis[i][nearestNode[2][i]] > dis[i][j]) {
                nearestNode[2][i] = j;
            }
            if(dis[i][nearestNode[1][i]] > dis[i][nearestNode[2][i]]) {
                swap(nearestNode[1][i], nearestNode[2][i]);
            }
            if(dis[i][nearestNode[0][i]] > dis[i][nearestNode[1][i]]) {
                swap(nearestNode[0][i], nearestNode[1][i]);
            }
        }
    }
    int ans = 2e9;
    for(int i : a) {
        for(int j : a) {
            if(i == j)
                continue;
            if(dis[i][j] == 1e9)
                continue;
            for(int k : a) {
                if(i == k || j == k)
                    continue;
                for(int it = 0; it < 3; it++) {
                    if(nearestNode[it][k] == i || nearestNode[it][k] == j || nearestNode[it][k] > n)
                        continue;
                    if(dis[k][nearestNode[it][k]] == 1e9)
                        continue;
                    ans = min(ans, dis[k][nearestNode[it][k]] + dis[i][j]);
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
2
5 4 4
1 2 1
3 4 2
4 5 5
5 3 8
3 1 5 2
6 6 4
1 2 5
2 4 7
4 6 50
6 5 3
1 5 15
3 5 6
1 5 4 6
*/
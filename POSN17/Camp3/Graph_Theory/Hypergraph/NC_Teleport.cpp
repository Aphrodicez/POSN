/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Hypergraph
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;
const int MaxT = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {

};

vector <int> adj[MaxN + MaxT];
queue <int> qu; 
int dis[MaxN + MaxT];

void solve() {
    memset(dis, -1, sizeof (dis));
    int n, a, t;
    scanf("%d %d %d", &n, &a, &t);
    for(int i = n + 1; i <= n + t; i++) {
        for(int j = 1; j <= a; j++) {
            int u;
            scanf("%d", &u);
            adj[u].emplace_back(i);
            adj[i].emplace_back(u);
        }
    }
    dis[1] = 0;
    qu.push(1);
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for(int x : adj[u]) {
            if(dis[x] != -1)
                continue;
            dis[x] = dis[u] + 1;
            qu.push(x);
        }
    }
    printf("%d\n", (dis[n] == -1) ? -1 : (dis[n] / 2) + 1);
}

int main() {
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
10 3 5
1 2 3
1 5 4
3 7 6
5 6 7
6 8 10
*/
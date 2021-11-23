/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Square Root Decomposition + Euler Tour
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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

vector <int> adj[MaxN];

int n;
int sq;

int level[MaxN];
int l[MaxN], r[MaxN];
int cnt = 0;

struct SQRT_D {
    pair <int, int> dp[2 * MaxN];
    pair <int, int> block[450];
    void build() {
        for(int i = 1; i <= cnt; i++) {
            dp[i] = make_pair(INF, INF);
            block[i / sq] = dp[i];
        }
    }
    void update(int l, int r, int lvl, int u) {
        for(int i = l; i <= r;) {
            if(i % sq == 0 && i + sq - 1 <= r) {
                block[i / sq] = min(block[i / sq], make_pair(lvl, u));
                i += sq;
                continue;
            }
            dp[i] = min(dp[i], make_pair(lvl, u));
            i++;
        }
    }
    int query(int l, int r, pair <int, int> res = make_pair(-1, -1)) {
        for(int i = l; i <= r;) {
            if(i % sq == 0 && i + sq - 1 <= r) {
                res = max(res, block[i / sq]);
                i += sq;
                continue;
            }
            if(block[i / sq] != make_pair(INF, INF)) {
                res = max(res, block[i / sq]);
            }
            else {
                res = max(res, dp[i]);
            }
            i++;
        }
        return res.second;
    }
};

void euler_tour(int u, int p) {
    level[u] = level[p] + 1;
    l[u] = ++cnt;
    for(int x : adj[u]) {
        if(x == p)
            continue;
        euler_tour(x, u);
    }
    r[u] = ++cnt;
}

SQRT_D sqd;

void solve() {
    int q;
    scanf("%d %d", &n, &q);
    sq = sqrt(2 * n);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    euler_tour(1, 1);
    sqd.build();
    while(q--) {
        int opr;
        scanf("%d", &opr);
        if(!opr) {
            int u;
            scanf("%d", &u);
            sqd.update(l[u], r[u], level[u], u);
            continue;
        }
        if(opr) {
            int u;
            scanf("%d", &u);
            int ans = sqd.query(l[u], r[u]);
            printf("%d\n", ans == INF ? -1 : ans);
        }
    }
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
9 6
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8
1 3
0 8
1 6
1 7
0 2
1 9
*/
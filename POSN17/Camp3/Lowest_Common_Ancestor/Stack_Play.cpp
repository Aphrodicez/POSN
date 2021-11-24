/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Lowest Common Ancestor
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

const int MaxN = 3e5 + 10;
const int logN = 20;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {

};

int level[MaxN], lca[logN + 1][MaxN];
int leaf[MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        char opr;
        scanf(" %c", &opr);
        if(opr == 'a') {
            int p;
            scanf("%d", &p);
            p = leaf[p];
            level[i] = level[p] + 1, lca[0][i] = p;
            for(int k = 1; k <= 20; k++) {
                lca[k][i] = lca[k - 1][lca[k - 1][i]];
            }
            leaf[i] = i;
            continue;
        }
        if(opr == 'b') {
            int p;
            scanf("%d", &p);
            p = leaf[p];
            leaf[i] = lca[0][p];
            if(!p) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", p);
            continue;
        }
        if(opr == 'c') {
            int p, u;
            scanf("%d %d", &p, &u);
            leaf[i] = leaf[p];
            p = leaf[p], u = leaf[u];
            if(level[p] > level[u])
                swap(u, p);
            for(int k = 20; k >= 0; k--) {
                if(level[lca[k][u]] < level[p])
                    continue;
                u = lca[k][u];
            }
            if(u == p) {
                printf("%d\n", level[u]);
                continue;
            }
            for(int k = 20; k >= 0; k--) {
                if(lca[k][u] == lca[k][p])
                    continue;
                u = lca[k][u];
                p = lca[k][p];
            }
            printf("%d\n", level[lca[0][u]]);
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
10
a 0
a 1
a 2
a 3
a 2
c 4 5
a 5
b 7
b 7
c 9 7
*/
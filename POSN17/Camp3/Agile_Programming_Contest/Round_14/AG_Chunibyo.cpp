/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Disjoint Set Union + Topological Sort
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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int p[MaxN];

int find_root(int u) {
    if(p[u] == u)
        return u;
    return p[u] = find_root(p[u]);
}

char s[20];

vector <int> g[MaxN], pgt[MaxN];
unordered_set <int> pg[MaxN];
unordered_set <int> roots;
int degin[MaxN], degout[MaxN];
int sumup[MaxN], sumdown[MaxN];
queue <int> qu;

void solve() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    iota(p + 1, p + 1 + m, 1);
    while(q--) {
        scanf(" %s", s);
        int len = strlen(s);
        int i = 0;
        int u = 0;
        for(; i < len && isdigit(s[i]); i++) {
            u *= 10;
            u += s[i] - '0';
        }
        char opr = s[i++];
        int v = 0;
        for(; i < len; i++) {
            v *= 10;
            v += s[i] - '0';
        }
        if(opr == '=')
            p[find_root(u)] = p[find_root(v)];
        if(opr == '>')
            g[u].emplace_back(v);
        if(opr == '<')
            g[v].emplace_back(u);
    }
    for(int i = 1; i <= m; i++) {
        int ru = find_root(i);
        roots.insert(ru);
        for(int x : g[i]) {
            int rx = find_root(x);
            if(pg[ru].find(rx) != pg[ru].end())
                continue;
            pg[ru].insert(rx);
            ++degin[rx];
            ++degout[ru];
        }
    }
    for(int u : roots) {
        if(!degin[u]) {
            qu.push(u);
        }
        for(int x : pg[u]) {
            pgt[x].emplace_back(u);
        }
    }
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for(int x : pg[u]) {
            sumup[x] = max(sumup[x], sumup[u] + 1);
            if(--degin[x] == 0) {
                qu.push(x);
            }
        }
    }
    for(int u : roots) {
        if(!degout[u]) {
            qu.push(u);
        }
    }
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for(int x : pgt[u]) {
            sumdown[x] = max(sumdown[x], sumdown[u] + 1);
            if(--degout[x] == 0) {
                qu.push(x);
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        int u = find_root(i);
        if(sumup[u] + sumdown[u] != n - 1) {
            printf("?\n");
            continue;
        }
        printf("K%d\n", sumdown[u] + 1);
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
3 5 3
1<2
2<4
3=5
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Breadth First Search + Valid Parentheses + Math
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

struct GRAPH {
    
};

char s[MaxN];
int a[MaxN];
vector <int> g[MaxN];
queue <int> qu;
int dis[2][MaxN];
bool visited[2][MaxN];
long long cnt[2][MaxN];

void solve() {
    int n, st, en;
    scanf("%d %d %d", &n, &st, &en);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    scanf(" %s", s + 1);
    if(s[st] != '(' || s[en] != ')') {
        printf("0\n");
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(s[i] == '(')
            a[i] = 1;
        else
            a[i] = -1;
    }
    visited[0][st] = true;
    dis[0][st] = a[st];
    qu.push(st);
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        cnt[0][dis[0][u]]++;
        for(auto x : g[u]) {
            if(visited[0][x])
                continue;
            int nextw = dis[0][u] + a[x];
            if(nextw < 0)
                continue;
            visited[0][x] = true;
            dis[0][x] = nextw;
            qu.push(x);
        }
    }
    visited[1][en] = true;
    dis[1][en] = a[en];
    qu.push(en);
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        cnt[1][dis[1][u] * -1]++;
        for(auto x : g[u]) {
            if(visited[1][x])
                continue;
            int nextw = dis[1][u] + a[x];
            if(nextw > 0)
                continue;
            visited[1][x] = true;
            dis[1][x] = nextw;
            qu.push(x);
        }
    }
    long long ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += 1ll * cnt[0][i] * cnt[1][i];
    }
    printf("%lld\n", ans);
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
4 2 1
1 2
2 3
3 4
)(()

7 2 6
1 2
2 3
2 4
3 5
3 6
6 7
)((()))
*/
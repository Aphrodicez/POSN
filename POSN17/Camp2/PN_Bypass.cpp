/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int dp[N];

v(int) g[N];

void dfs(int u, int p){
    if(dp[u])
        return ;
    dp[u] = 1;
    int mx = 0;
    for(int x: g[u]){
        if(x == p)
            continue;
        dfs(x, u);
        mx = max(mx, dp[x]);
    }
    dp[u] += mx;
    return ;
}

void solve() {
    int n, u, v;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        g[i].clear();
    }
    for(int i = 1; i <= n - 1; i++){
        scanf("%d %d", &u, &v);
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1, 1);
    printf("%d\n", dp[1] - 2);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--){
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
6
1 3
2 3
3 4
4 5
5 6
9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
*/
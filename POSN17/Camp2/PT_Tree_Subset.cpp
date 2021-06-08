/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
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
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

i64 tree[N];

v(i64) g[N];

i64 dp[2][N];

void dfs(i64 u, i64 p){
    if(dp[1][u] || dp[0][u])
        return ;
    dp[1][u] = tree[u];
    for(i64 x: g[u]){
        if(x == p)
            continue;
        dfs(x, u);
        dp[0][u] += max(dp[1][x], dp[0][x]);
        dp[1][u] += dp[0][x];
    }
    return;
}

void solve() {
    i64 n, u, v;
    scanf("%lld", &n);
    for(i64 i = 1; i <= n; i++){
        scanf("%lld", &tree[i]);
        g[i].clear();
        dp[0][i] = dp[1][i] = 0;
    }
    for(i64 i = 1; i <= n - 1; i++){
        scanf("%lld %lld", &u, &v);
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1, 1);
    printf("%lld\n", max(dp[0][1], dp[1][1]));
}

int main() {
    i64 q;
    scanf("%lld", &q);
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
3
3 4 3
1 2
2 3
5
3 2 10 10 10
1 2
2 3
1 5
4 2
*/
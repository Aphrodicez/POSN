/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Depth First Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

using i64 = long long;

#define eb emplace_back
#define v(a) vector <a>
#define heap(a) priority_queue <a>

const i64 N = 1e3 + 10;
const i64 M = 2e5 + 10;

i64 w[N], degin[N], mark[N];
v(i64) g[N];

i64 dfs(i64 u, i64 p){
    if(mark[u])
        return 0;
    mark[u] = 1;
    i64 sum = w[u];
    if(!g[u].size())
        return sum;
    for(auto &x : g[u]){
        if(x == p)
            continue;
        sum += dfs(x, u);
    }
    return sum;
}

void solve() {
    i64 n, m, u, v, mx = -1, ans;
    scanf("%lld %lld", &n, &m);
    for(i64 i = 1; i <= n; i++){
        scanf("%lld", &w[i]);
    }
    for(i64 i = 1; i <= m; i++){
        scanf("%lld %lld", &u, &v);
        g[u].eb(v);
        degin[v]++;
    }
    for(i64 i = 1; i <= n; i++){
        if(degin[i])
            continue;
        i64 sum = 0;
        sum = dfs(i, i);
        if(sum > mx){
            mx = sum;
            ans = i;
        }
        memset(mark, 0, sizeof mark);
    }
    printf("%lld %lld", ans, mx);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
5 6
7 2 3 9 4
1 3
2 5
4 1
3 5
4 5
2 1
*/
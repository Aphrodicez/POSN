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

struct A{
    int u, w;
};

const int N = 1e2 + 10;
const int K = 1e2 + 10;

vector <A> g[N];

int dp[K][N], tree[N];

int n;

int dfs(int u, int p, int k, int w){
    if(u > n)
        return 0; 
    if(k <= 0)
        return 0;
    if(dp[k][u])
        return dp[k][u];
    vector <A> child;
    for(auto &x : g[u]){
        if(x.u != p)
            child.push_back(x);
    }
    while(child.size() < 2)
        child.push_back({n + 1, 0});
    dp[k][u] = w;
    A l = child[0];
    A r = child[1];
    int sum = 0;
    for(int mid = 0; mid <= k - 1; mid++){
        sum = max(sum, dfs(l.u, u, mid, l.w) + dfs(r.u, u, k - 1 - mid, r.w));
    }
    dp[k][u] += sum;
    return dp[k][u];
}

void solve() {
    int k, u, v, w;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n - 1; i++){
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 1, k + 1, 0);
    printf("%d\n", dp[k + 1][1]);
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
5 2
1 3 1
1 4 10
2 3 20
3 5 20
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming On Tree
    Status	: Accepeted
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

const int N = 5e3 + 10;
const int K = 1e2 + 10;

int n, k;

int tree[N], dp[K][N];

int dfs(int u, int k){
    if(u > n)
        return 0;
    if(k <= 0)
        return 0;
    if(dp[k][u])
        return dp[k][u];

    dp[k][u] = tree[u];
    int sum = 0;
    for(int mid = 0; mid <= k - 1; mid++){
        int l = u * 2, r = u * 2 + 1;
        sum = max(sum, dfs(l, mid) + dfs(r, k - 1 - mid));
    }
    dp[k][u] += sum;
    return dp[k][u];
}

void solve() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &tree[i]);
    }
    for(int i = 1; i <= n; i++)
        dfs(i, k);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[k][i]);
    }
    printf("%d", ans);
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
10 5
3 7 1 9 6 2 6 5 4 1
*/
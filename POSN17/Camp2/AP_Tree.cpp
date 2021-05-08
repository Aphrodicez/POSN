/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Dynamic Programming On Tree
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void setIO();

const int N = 1e5 + 10;

i64 val[N], deg[N], tree[N];

vector <i64> g[N];

queue <i64> qu;

void solve(){
    memset(tree, 0, sizeof tree);
    memset(deg, 0, sizeof deg);
    i64 n, u, v, all = 0;
    cin >> n;
    for(i64 i = 1; i <= n - 1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(i64 i = 1; i <= n; i++){
        if(deg[i]==1){
            deg[i]--;
            qu.push(i);
        }
        cin >> val[i];
        all += val[i];
        tree[i] = val[i];
    }
    while(!qu.empty()){
        i64 u = qu.front();
        qu.pop();
        for(auto x: g[u]){
            if(!deg[x])
                continue;
            tree[x] += tree[u];
            deg[x]--;
            if(deg[x] == 1){
                deg[x]--;
                qu.push(x); 
            }
        }
    }
    i64 ans = 1e18;
    for(i64 i = 1; i <= n; i++){
        ans = min(ans, abs(all - 2*tree[i]));
        g[i].clear();
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    i64 q;
    cin >> q;
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
1 2
1 4
1 5
5 6
6 3
2 1 3 3 4 6
3
1 2
1 3
10 4 3
*/
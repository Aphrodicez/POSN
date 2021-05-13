/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Kahn's Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct HEAP{
    int u;
    bool operator < (const HEAP &o) const{
        return u > o.u;
    }
};

#define eb emplace_back
#define v(a) vector <a>
#define heap(a) priority_queue <a>

void setIO();

const int N = 1e5 + 10;
const int M = 1e5 + 10;

v(int) g[N], ans;

int deg[N];

heap(HEAP) he;

void solve() {
    while(!he.empty())
        he.pop();
    memset(deg, 0, sizeof deg);
    ans.clear();
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &u, &v);
        g[u].eb(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(!deg[i]){
            he.push({i});
        }
    }
    while(!he.empty()){
        int u = he.top().u;
        he.pop();
        ans.eb(u);
        for(auto x : g[u]){
            if(!deg[x])
                continue;
            deg[x]--;
            if(!deg[x])
                he.push({x});
        }
    }
    for(int i = 1; i <= n; i++)
        g[i].clear();
    if(ans.size() != n){
        printf("No\n");
        return ;
    }
    printf("Yes ");
    for(int i : ans)
        printf("%d ", i);
    printf("\n");
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
5 5
1 2
1 3
2 4
3 5
4 5
5 6
1 2
1 3
2 4
3 5
4 5
4 1
*/
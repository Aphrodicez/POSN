/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Bipartite Graph
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e5 + 10;

int mark[N];

vector <int> g[N];

bool bipartite_Check(int u, int color){
    if(mark[u]){
        if(mark[u] == color)
            return true;
        return false;
    }
    mark[u] = color;
    for(auto &x : g[u]){
        if(!bipartite_Check(x, 3 - color))
            return false;
    }
    return true;
}

void solve(){
    memset(mark, 0, sizeof mark);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(bipartite_Check(1, 1))
        cout << "yes\n";
    else
        cout << "no\n";
    for(int i = 1; i <= n; i++){
        g[i].clear();
    }
}

int main() {
    setIO();
    int q;
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
4 4
1 2
2 3
3 4
4 1
3 3
1 2
2 3
3 1
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Bipartite Graph + B-Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct A{
    int u, idx;
};


const int N = 1e5 + 10;
const int M = 3e5 + 10;

int mark[N];

int root[M];

vector <A> g[N];

bool bipartite_Check(int u, int color, int rBound){
    if(mark[u]){
        if(mark[u] == color)
            return true;
        return false;    
    }
    mark[u] = color;
    for(auto x : g[u]){
        if(x.idx > rBound)
            continue;
        if(!bipartite_Check(x.u, 3 - color, rBound))
            return false;
    }
    return true;
}

void solve(){
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        root[i] = u;
    }
    int l = 1, r = m;
    while(l < r){
        memset(mark, 0, sizeof mark);
        int mid = l + (r - l + 1) / 2;
        if( bipartite_Check(root[mid], 1, mid) )
            l = mid;
        else
            r = mid - 1;
    }
    cout << l + 1 << "\n";
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
6 8
3 4
1 2
5 6
1 6
1 3
4 5
2 4
2 6
*/
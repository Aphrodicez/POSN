/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define fi(a, b) for(int i=a; i<=b; i++)

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int a[100010], all;

vector <int> g[100010];

int mn = 1e9;

int dfs(int u, int p){
    int sum = 0, allchild = 0, childxor = 0;
    for(auto x: g[u]){
        if(x==p)
            continue;
        childxor = dfs(x, u);
        sum += childxor;
        allchild ^= childxor;
    }
    mn = min(mn, sum + ((all ^ allchild) ^ a[u]));
    return (allchild ^ a[u]);
}

int main(){
    setIO();
    int n, u, v;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        all ^= a[i];
    }
    for(int i=1; i<n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    u = dfs(1, 1);
    cout << mn;
    return 0;
}
/*
5
7 3 8 5 2
4 3
1 5
3 2
3 1
*/
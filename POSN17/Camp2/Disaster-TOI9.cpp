/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Euler Path
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 30;
const int M = 3e2 + 10;

struct A{
    int u, idx;
};

bool cmpidx(A a, A b){
    return a.u < b.u;
}

vector <A> g[N];

int deg[N];

int mark[M], ans[M];

int edge;

int tail = 0;

void dfs(int u, int edgeUsed){
    ans[edgeUsed] = u;
    if(edgeUsed == edge){
        for(int i = 0; i <= edgeUsed; i++){
            cout << char(ans[i] + 'A') << " ";
        }
        exit(0);
    }
    for(auto &x : g[u]){
        if(mark[x.idx])
            continue;
        mark[x.idx] = 1;
        dfs(x.u, edgeUsed + 1);
        mark[x.idx] = 0;
    }
}

void solve(){
    int m;
    char u, v;
    cin >> m;
    edge = m;
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        g[u - 'A'].push_back({v - 'A', i});
        g[v - 'A'].push_back({u - 'A', i});
        deg[u - 'A']++;
        deg[v - 'A']++;
    }
    int st = -1, secondst = -1;
    for(int i = 0; i < 26; i++){
        sort(g[i].begin(), g[i].end(), cmpidx);
        if(deg[i] && secondst == -1)
            secondst = i;
        if( (deg[i]%2) && st == -1)
            st = i;
    }
    if(st == -1)
        st = secondst;
    dfs(st, 0);
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
6
AB
AE
BD
BC
CE
DE

4
AB
DA
BC
DC
*/
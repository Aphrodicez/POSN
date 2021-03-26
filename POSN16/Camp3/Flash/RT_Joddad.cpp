/*
    TASK    : RT_Joddad
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

struct A{
    ll u;
    double w, vel,
};

double g[210][210], dis[210][210];

priority_queue <A> he;

int main(){
    setIO();
    int n, m, q, u, v, w, st, en;
    string s;
    double vel, tir;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            g[i][j] = LONG_LONG_MAX;
        }
    }
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    while(q--){
        cin >> s;

        if(s=="travel"){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(i==j){
                        dis[i][j] = 0;
                        continue;
                    }
                    dis[i][j] = LONG_LONG_MAX;
                }
            }
            cin >> st >> en >> vel >> tir;
            he.push({st, 0, vel, tir});
        }
    }
    return 0;
}
/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct A{
    ll u, w, st;
    bool operator  < (const A& o) const{
        return w > o.w;
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

priority_queue <A> he;

vector <A> g[2010];

ll dis[2010][2010];

A now;

int main(){
    ll n, st, en, m, u, v, w, nextst, h, sum, q;
    scanf("%lld %lld %lld %lld", &n, &st, &en, &m);
    for(ll i = 0; i < m; i++){
        scanf("%lld %lld %lld", &u, &v, &w);
        g[u].push_back({v, w, 0});
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            dis[i][j] = 1e9;
        }
    }
    dis[0][st] = 0;
    he.push({st, 0, 0});
    while(!he.empty()){
        now = he.top();
        he.pop();
        for(auto x: g[now.u]){
            nextst = now.st + 1;
            if(now.u==st)
                nextst--;
            if(dis[nextst][x.u] <= dis[now.st][now.u] + x.w)
                continue;
            dis[nextst][x.u] = dis[now.st][now.u] + x.w;
            he.push({x.u, dis[nextst][x.u], nextst});
        }
    }
    scanf("%lld", &q);
    while(q--){
        ll ans = 1e15;
        scanf("%lld", &h);
        for(ll i = 0; i < n - 1; i++){
            sum = dis[i][en] + h * i;
            ans = min(sum, ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
8 0 7 14
0 1 10
0 3 14
0 4 8
1 2 2
2 7 2
2 3 4
3 7 15
3 4 9
5 3 7
5 7 2
4 5 5
4 6 1
6 5 1
6 4 3
4
0 10 2 30
*/

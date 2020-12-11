/*
    TASK    : RT_Marathon
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

#define pb push_back

struct A{
    int val, str;
    bool operator < (const A& o) const{
        return str < o.str;
    }
};

struct B{
    int u, str, tim;
    bool operator < (const B& o) const{
        return tim > o.tim;
    }
};

A shoe[100010];
vector <B> g[100010];
priority_queue <B> he;
B now;

int dis[100010];

int main(){
    //setIO();
    int n, m, k, lim, t, u, v, str, tim, val, l, r, mid, mn = 1e9;
    scanf("%d %d %d %d", &n, &m, &k, &lim);
    for(int i=1; i<=m; i++){
        scanf("%d %d %d %d", &u, &v, &str, &tim);
        g[u].pb({v, str, tim});
        g[v].pb({u, str, tim});
    }
    for(int i=1; i<=k; i++){
        cin >> shoe[i].val >> shoe[i].str;
    }
    shoe[k+1].val = shoe[k+1].str = 1e9;
    sort(shoe + 1, shoe + k + 1);
    l = 1, r = k + 1;
    while(l < r){
        mid = l + (r-l) / 2;
        for(int i = 1; i<=n; i++){
            dis[i] = 1e9;
        }
        he.push({1, 0, 0});
        dis[1] = 0;
        while(!he.empty()){
            now = he.top();
            he.pop();
            if(now.u == n)  break;
            for(auto x: g[now.u]){
                if(x.str > shoe[mid].str)
                    continue;            
                if(dis[x.u] <= dis[now.u] + x.tim)
                    continue;
                dis[x.u] = dis[now.u] + x.tim;
                he.push({x.u, 0, dis[x.u]});
            }
        }
        while(!he.empty())
            he.pop();
        if(dis[n] > lim){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }      
    if(l==k+1){
        cout << "-1";
    }
    else{
        for(int i = k; i >= l; i--){
            mn = min(mn, shoe[i].val);
        }
        cout << mn;
    }
    return 0;
}
/*
2 2 3 50
1 2 50 100
1 2 100 50
40 70
30 50
70 100
*/
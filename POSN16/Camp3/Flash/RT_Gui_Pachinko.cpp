/*
    TASK    : 0
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

#define ll long long

vector <ll> g[100010];

vector <ll> path;

ll mxsub[100010], dp[100010];

bool cmp(ll a, ll b){
    return mxsub[a] < mxsub[b];
}

ll fmx(ll u, ll p){
    mxsub[u] = u;
    for(auto x: g[u]){
        if(x==p)
            continue;
        mxsub[u] = max(mxsub[u], fmx(x, u));
    }
    return mxsub[u];
}

void dfs(ll u, ll p){
    for(auto x: g[u]){
        if(x==p)
            continue;
        dfs(x, u);
    }
    path.push_back(u);
    return ;
}

int main(){
    setIO();
    ll n, m, p, root;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        cin >> p;
        if(p==0)
            root = i;
        g[p].push_back(i);
    }
    fmx(root, root);
    for(ll i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end(), cmp);
    }
    path.push_back(0);
    dfs(root, root);
    for(ll i=1; i < path.size(); i++){
        dp[i] = dp[i-1] + path[i];
    }
    ll it = 0, val, opr;
    while(m--){
        cin >> opr;
        if(opr==1){
            cin >> val;
            it += val;
            it = min(it, n);
            cout << path[it] << "\n";
        }
        else if(opr==2){
            cin >> val;
            it -= val;
            it = max(0ll, it);
        }
        else if(opr==3){
            cout << dp[it] << "\n";
        }
    }
    return 0;
}
/*
7 5
7
7
5
0
4
4
4
1 3
1 1
3
1 3
3
*/
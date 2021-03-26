/*
    TASK    : Technology_TOI14
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
#define pii pair <int, int>

struct A{
    int u, lvl;
    bool operator < (const A& o) const{
        return lvl > o.lvl;
    }
};

int n, k, t, lvlNeed, u, v, i;

int lvl[100010], deg[100010], lvlcount[10010], fakelvl[100010], mark[100010];

vector <int> g[100010], vec;

priority_queue <A> pq;

A tmp;

void dfs(int u){
    mark[u] = 1;
    for(auto x : g[u]){
        if(!mark[x])
            dfs(x);
        fakelvl[u] = min(fakelvl[u], fakelvl[x]);
    }
}

int main(){
    //setIO();
    scanf("%d %d %d", &n, &k, &t);
    for(u=1; u<=n; u++){
        scanf("%d %d", &lvl[u], &lvlNeed);
        lvlcount[lvl[u]]++;
        fakelvl[u] = lvl[u];
        for(i=1; i<=lvlNeed; i++){
            scanf("%d", &v);
            deg[u]++;
            g[v].pb(u);
        }
    }
    for(i=1; i<=n; i++){
        if(deg[i]==0){
            dfs(i);
            pq.push({i, fakelvl[i]});
        }
    }
    /*
    for(i=1; i<=n; i++){
        printf("%d ",fakelvl[i]);
    }
    printf("\n");*/

    while(!pq.empty() && t--){
        tmp = pq.top();
        pq.pop();
        //printf("HAHA %d\n", tmp.u);
        lvlcount[lvl[tmp.u]]--;
        for(auto x : g[tmp.u]){
            deg[x]--;
            if(deg[x]==0){
                pq.push({x, fakelvl[x]});
            }
        }
    }
    if(lvlcount[1]!=0){
        printf("-1");
        return 0;
    }
    for(i=2; i<=k; i++){
        ///printf("%d\n",lvlcount[i]);
        if(lvlcount[i]!=0){
            printf("%d", i - 1);
            return 0;
        }
    }
    printf("%d", k);
    return 0;
}
/*
6 5 4
1 0
5 1 1
2 1 2
4 2 3 5
3 1 6
2 1 1
*/
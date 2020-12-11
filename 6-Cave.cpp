/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: KVIS
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int u,w,state;
    bool operator < (const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> hp;
vector<A> g[2010];
A tt;
int dis[2010][2010];//node n(edge)
int main()
{
    int n,p,u,e,q,r,t,i,l,ti,j,mi;
    scanf("%d %d %d %d",&n,&p,&u,&e);
    for(i=0;i<e;i++){
        scanf("%d %d %d",&q,&r,&t);
        g[q].push_back({r,t,0});
    }
    for(i=0;i<n;i++)
        for(j=0;j<=n-1;j++)
            dis[i][j]=1e9;
    dis[p][0]=0,hp.push({p,0,0});
    while(!hp.empty()){
        tt=hp.top();
        hp.pop();
        for(auto x:g[tt.u]){
            if(tt.u==p){
                if(dis[x.u][tt.state]>dis[tt.u][tt.state]+x.w){
                    dis[x.u][tt.state]=dis[tt.u][tt.state]+x.w;
                    hp.push({x.u,dis[x.u][tt.state],tt.state});
                }
            }else if(tt.u!=p){
                if(dis[x.u][tt.state+1]>dis[tt.u][tt.state]+x.w){
                    dis[x.u][tt.state+1]=dis[tt.u][tt.state]+x.w;
                    hp.push({x.u,dis[x.u][tt.state+1],tt.state+1});
                }
            }
        }
    }
    /*for(i=0;i<=n-1;i++)
        printf("%d\n",dis[u][i]);*/
    scanf("%d",&l);
    while(l--){
        mi=1e9;
        scanf("%d",&ti);
        for(i=0;i<n-1;i++)
            mi=min(mi,dis[u][i]+i*ti);
        printf("%d\n",mi);
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

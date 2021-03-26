#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,v,p;
    bool operator < (const A&o) const{
        if(s!=o.s) return s<o.s;
        return v>o.v;
    }
};
A a[1000010];
int ans[500010],cnt,ma[500010];
int main(){
    int s,e,p,i,n,m,k,l;
    scanf("%d %d %d",&n,&k,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&s,&e);
        a[i]={s,1,i};
        a[i+n]={e,-1,i};
    }
    sort(a+1,a+2*n+1);
    for(i=1;i<=2*n;i++){
        if(ma[a[i].p]==1) continue;
        cnt+=a[i].v;
        if(a[i].v==1){
            if(cnt>k) ans[a[i].p]=1,cnt-=1,ma[a[i].p]=1;
        }
    }
    for(i=0;i<m;i++){
        scanf("%d",&l);
        if(ans[l]==1) printf("N ");
        else printf("Y ");
    }
return 0;
}
/*
6 1 4
3 7 2 4 1 3 7 8 8 10 9 15
3 5 4 1
*/

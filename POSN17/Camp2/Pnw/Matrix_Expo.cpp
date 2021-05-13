#include<bits/stdc++.h>
using namespace std;
struct A{
 long long a[5][5];
};
long long n,mod;
A mul(A a,A b){
    A tmp;
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            tmp.a[i][j]=0;
            for(long long k=0;k<n;k++){
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=mod;
            }
        }
    }
    return tmp;
}
A p[65],ans;
int main()
{
    long long m;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            scanf("%lld",&p[0].a[i][j]);
        }
    }
    ans=p[0];
    scanf("%lld %lld",&m,&mod);
    if(m==0){
        for(long long i=0;i<n;i++){
            for(long long j=0;j<n;j++){
                if(i==j)    printf("%lld ",1%mod);
                else        printf("%lld ",0);
            }
            printf("\n");
        }
        return 0;
    }
    --m;
    for(long long i=1;i<=63;i++)p[i]=mul(p[i-1],p[i-1]);
    for(long long i=0;i<=63;i++)
        if((1ll<<i)&m)
            ans=mul(ans,p[i]);
     for(long long i=0;i<n;i++){
            for(long long j=0;j<n;j++){
                printf("%lld ",ans.a[i][j]);
            }
            printf("\n");

        }

return 0;
}
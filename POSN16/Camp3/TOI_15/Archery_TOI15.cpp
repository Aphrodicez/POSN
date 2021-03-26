/*
    TASK    : Archery_TOI15
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct A{
    ll mxh, h;
    bool operator < (const A& o) const{
        return h < o.h;
    }
};


A a[500010];

ll mxh[500010], h[500010];

int main(){
    //setIO();
    ll n, l, r, suml, sumr, ans, mn = 1e18, minh = 1e18;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i].mxh);
        minh = min(minh, a[i].mxh);
    }
    for(ll i = 1; i <= n ; i++){
        scanf("%lld", &a[i].h);
    }
    sort(a+1, a+1+n);

    for(ll i = 1; i<=n; i++){
        mxh[i] = mxh[i-1] + a[i].mxh + a[i].h;
        h[i] = h[i-1] + a[i].h;
    }
    for(ll i = 1; i <= n; i++){
        if(minh < a[i].h)
            break;
        
        l = i - 1;
        r = i + 1;
        suml = mxh[l] - mxh[0];
        sumr = h[n] - h[r-1];
        suml -= a[i].h*(l-0);
        sumr -= a[i].h*(n-r+1);
        if(suml+sumr < mn){
            mn = suml + sumr;
            ans = a[i].h;
        }
    }
    printf("%lld %lld\n", ans, mn);
    return 0;
}
/*
3
4 6 5
3 2 4
*/
/*
3
5 8 6
2 4 1
*/
/*
5
7 9 6 8 5
4 5 1 3 5
*/
/*
5
9 4 5 6 8
4 4 5 1 3
*/
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
    ll u, v, w;
    bool operator < (const A& o) const{
        return w > o.w;
    }
};

struct B{
    ll w, val;
    bool operator < (const B& o) const{
        if(w!=o.w)
            return w < o.w;
        return val > o.val; 
    }
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

priority_queue <A> he1, he2;

ll p[3010];

B a[300010];

ll fr(ll i){
    if(p[i]==i)
        return i;
    return p[i] = fr(p[i]);
}

int main(){
    setIO();
    ll n, m, q, u, v, w, type, ru, rv, sum = 0, cnt = 0, l, r, mid;
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; i++)
        p[i] = i;
    for(ll i = 1; i <= m; i++){
        scanf("%lld %lld %lld %lld", &u, &v, &w, &type);
        if(type)
            he1.push({u, v, w});
        else
            he2.push({u, v, w});
    }
    while(!he1.empty()){
        u = he1.top().u;
        v = he1.top().v;
        w = he1.top().w;
        he1.pop();
        ru = fr(u);
        rv = fr(v);
        if(ru==rv)
            continue;
        p[ru] = rv;
        cnt++;
    }
    scanf("%lld", &q);
    for(ll i = 0; i < q; i++){
        scanf("%lld %lld", &a[i].w, &a[i].val);
    }
    sort(a, a+q);
    for(ll i = q - 2; i >= 0; i--){
        a[i].val = min(a[i].val, a[i+1].val);
    }
    /*
    for(ll i = 0; i < q; i++){
        printf("%lld %lld\n", a[i].w, a[i].val);
    }*/
    while(!he2.empty()){
        u = he2.top().u;
        v = he2.top().v;
        w = he2.top().w;
        he2.pop();
        if(cnt==n-1){
            printf("%lld", sum);
            return 0;
        }
        ru = fr(u);
        rv = fr(v);
        if(ru==rv)
            continue;
        p[ru] = rv;
        cnt++;
        l = 0, r = q;
        while(l < r){
            mid = (l+r) / 2;
            if(a[mid].w < w)
                l = mid + 1;
            else
                r = mid;
        }
        sum += a[l].val;
    }
    printf("%lld", sum);
    return 0;
}
/*
6 8
0 1 19 0
1 2 50 1
1 3 5 0
2 3 18 0
0 4 32 0
3 4 22 0
2 5 70 0
4 5 20 1
8
5 60
50 200
75 350
20 100
40 145
15 50
35 150
8 60
*/
/*
    TASK    : Chest_TOI10
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
    ll idx, fac[10];
    bool operator < (const A&o) const{
        if(idx!=o.idx)
            return idx < o.idx;
        return fac[2] + fac[3] + fac[5] + fac[7] < o.fac[2] + o.fac[3] + o.fac[5] + o.fac[7];
    }
};

ll srt[] = {2, 3, 5, 7}, n, m, i, x, st, en, sum, mx, cnt;

A tmp[12], a[400010];

ll fac[12];

int main(){
    setIO();
    cin >> m >> n;
    for(i=2; i<=10; i++){
        x = i;
        for(ll j: srt){
            while(x%j==0){
                tmp[i].fac[j]++;
                x /= j;
            }
        }
    }
    for(i=1; i<=m; i++){
        cin >> x >> st >> en;
        a[i].idx = st;
        a[i+m].idx = en + 1;
        for(ll j : srt){
            a[i].fac[j] += tmp[x].fac[j];
            a[i+m].fac[j] -= tmp[x].fac[j];
        }
    }
    sort(a + 1, a + 2*m + 1);
    for(ll i = 1; i < 2*m; i++){
        for(ll j : srt)
            fac[j] += a[i].fac[j];
        sum = (fac[2] + 1) * (fac[3] + 1) * (fac[5] + 1) * (fac[7] + 1);
        if(sum > mx){
            mx = sum;
            cnt = a[i+1].idx - a[i].idx;
        }
        else if(sum==mx){
            cnt += a[i+1].idx - a[i].idx;
        }
    }
    cout << mx << " " << cnt;
    return 0;
}

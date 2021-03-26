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
    ll x, y;
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, i, cnt, j, k, num, idx;

ll ans;

ll a[100010], tmp[100010];

ll qs[100010];

void mSort(ll l, ll r){
    if(l>=r){
        return;
    }
    ll mid = (l + r) / 2;
    mSort(l, mid);
    mSort(mid+1,r);
    i = l, j = mid + 1;
    k = l;
    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            tmp[k++] = a[i++];
        }
        else{
            ans += (mid - i + 1) * a[j];
            ans += qs[mid] - qs[i - 1];
            tmp[k++] = a[j++];
        }
    }
    while(i<=mid)
        tmp[k++] = a[i++];
    while(j<=r)
        tmp[k++] = a[j++];
    for(i=l; i<=r; i++){
        a[i] = tmp[i];
        qs[i] = qs[i-1] + a[i];
    }
}



int main(){
    setIO();
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> num >> idx;
        a[idx] = num;
    }
    for(i=1; i<=n; i++){
        qs[i] = a[i] + qs[i-1];
    }
    mSort(1, n);
    cout << ans;
    return 0;
}
/*
6
2 1 7 6 9 3 18 4 3 2 5 5
*/

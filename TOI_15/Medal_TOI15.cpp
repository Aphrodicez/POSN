/*
    TASK    : Medal_TOI15
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

ll a[500010], b[500010];

int main(){
    setIO();
    ll n, num, sum = 0, last;
    cin >> n ;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n, greater<ll> ());

    for(ll i = 0; i < n ; i++){
        a[i] += b[i];
    }

    sort(a, a+n);

    last = a[0];
    for(ll i=1; i<n; i++){
        sum += abs(a[i] - last);
        last = a[i];
    }
    cout << abs(sum);
    return 0;
}
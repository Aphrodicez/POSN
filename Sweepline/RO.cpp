/*
    TASK    : RO
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

map <ll, ll> mp;
ll qs[1000010];

int main(){
    setIO();
    ll n, k, ans = 0, now, i;
    string s;
    cin >> n >> k;
    cin >> s;
    for(i=1; i<=n; i++){
        if(s[i-1]=='R')
            now = -1*k;
        else
            now = 1;
        qs[i] = qs[i-1] + now;
        if(qs[i]==0){
            ans = i;
            continue;
        }
        if(mp[qs[i]]==0){
            mp[qs[i]] = i;
            continue;
        }
        ans = max(ans, i - mp[qs[i]]);        

    }
    cout << ans;
    return 0;
}
/*
4 3
ROOO
*/
/*
15 3
RORROOROOROOORO
*/
/*
17 3
OROOOOOROOOOORRRR
*/
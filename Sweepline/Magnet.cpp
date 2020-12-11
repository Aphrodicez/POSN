/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pll pair <ll, ll>

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector <ll> vec, ans;

ll n, m, q, i, ask, l, r, idx;

int main(){
    //setIO();
    scanf("%lld %lld %lld", &n, &m, &q);
    for(i=0; i<m; i++){
        scanf("%lld %lld", &l, &r);
        vec.pb(l);
        vec.pb(l+r);
    }
    sort(vec.begin(), vec.end());
    ans.pb(1);
    for(i=0; i<vec.size(); i++){
        if(vec[i]==vec[i+1]){
            i++;
            continue;
        }
        ans.pb(vec[i]);
    }
    ans.pb(n + 1);
    while (q--){
        /* code */
        scanf("%lld", &ask);
        idx = upper_bound(ans.begin(), ans.end(), ask) - ans.begin();
        printf("%lld\n", ans[idx] - ans[idx - 1]);
    }
    return 0;
}
/*
10 3 2
2 4
4 5
3 7
7
5
*/
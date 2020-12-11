/*
    TASK    : 0
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

vector <pair <ll, ll>> vec;

int main(){
    //setIO();
    ll q, n, x, y, z, under, i, l, r;
    scanf("%lld", &q);
    while(q--){
        scanf("%lld %lld %lld %lld", &n, &x, &y, &z);
        under = n;
        ll mx = -1, sum = n*x, ans = 0;
        for(i=0; i<n; i++){
            scanf("%lld %lld", &l, &r);
            vec.push_back({l, y-x});
            vec.push_back({r+1, z-y});
        }
        sort(vec.begin(), vec.end());
        for(i=0; i<vec.size(); i++){
            sum += vec[i].second;
            if(sum >= mx){
                mx = sum;
                ans = max(sum, ans);
                //printf("%d %d %d\n",vec[i].first, vec[i+1].first, under);
            }
            //printf("%d %d %d\n",vec[i].first, vec[i+1].first, under);
        }
        vec.clear();
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1
4 7 9 6
5 8
3 4
13 20
7 10
*/
/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

vector <pair <long long, long long>> vec;

int main(){
    //setIO();
    long long i, n, l, r, ans = 0, sum = 0;
    scanf("%lld", &n);
    for(i=1; i<=n; i++){
        scanf("%lld %lld", &l, &r);
        vec.push_back({l, 1});
        vec.push_back({r + 1, -1});
    }
    sort(vec.begin(), vec.end());
    for(i=0; i<vec.size() -1; i++){
        sum += vec[i].second;
        if(sum > 1){
            ans += (sum - 1) * (vec[i+1].first - vec[i].first);
        }
    }
    printf("%lld", ans);
    return 0;
}
/*
3
1 5
4 8
3 11
*/
/*
4
2 5
6 8
9 12
14 19
*/
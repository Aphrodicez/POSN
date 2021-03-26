/*
    TASK    : Schedules_TOI6
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

struct A{
    int st, fi, use;
};

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

A a[500100];

int dp[500100], mark[500100];

int n, k, m, st, fi, mx, i, ask;

int main(){
    setIO();
    cin >> n >> k >> m;
    for(i=1; i<=n; i++){
        cin >> st >> fi;
        mark[st] = i;
        a[i].st = st;
        a[i].fi = fi+1;
        a[i].use = 1;
        dp[st]++;
        dp[fi+1]--;
        mx = max(a[i].fi, mx);
    }
    for(i=1; i<=mx; i++){
        dp[i] += dp[i-1];
        if(dp[i] > k){
            dp[i]--;
            dp[a[mark[i]].fi]++;
            a[mark[i]].use = 0;
        }
    }
    for(i=1; i<=m; i++){
        cin >> ask;
        if(a[ask].use== 1)
            cout << "Y ";
        else
            cout << "N ";
    }
    return 0;
}

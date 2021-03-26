/*
    TASK    : Segi_Tiga_Operation_TOI11
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, tc, i, x, y;
char str[260];

int dp[260][260][3];

vector <pair <int, int>> segi[3];

int divide (int l, int r, int target){
    if(dp[l][r][target] != -1)
        return dp[l][r][target];
    if(l==r){
        if(target==str[l] - '0')
            return dp[l][r][target] = 1;
        else
            return dp[l][r][target] = 0;
    }
    for(int i = l; i < r; i++){
        for(auto x: segi[target]){
            if(divide(l, i, x.first) && divide(i+1, r, x.second))
                return dp[l][r][target] = 1;
        }
    }
    return dp[l][r][target] = 0;
}

int main(){
    //setIO();
    segi[0].pb({0, 2});
    segi[1].pb({0, 1});
    segi[1].pb({1, 1});
    segi[1].pb({1, 2});
    segi[1].pb({2, 2});
    segi[2].pb({0, 0});
    segi[2].pb({1, 0});
    segi[2].pb({2, 1});

    for(tc = 1; tc <= 20; tc++){
        scanf("%lld %s",&n, str);
        memset(dp, -1, sizeof dp);
        if(divide(0, n-1, 0) == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
/*
4 0201
5 10212
6 002000
*/

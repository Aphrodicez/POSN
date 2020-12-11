/*
    TASK    : FC_Pay_Male_O1
    LANG    : CPP
    AUTHOR  : Aphrodicez
    TIME    : O (n^3)
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define MOD (ll) 100003 

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll dp[110][110][110][5];

/// a, b, c, last
/// last : a = 1, b = 2, c = 3

ll solve(ll a, ll b, ll c, ll last){
    int suma = 0, sumb = 0, sumc = 0;
    if(a < 0 || b < 0 || c < 0)
        return 0;    
    if(dp[a][b][c][last]!=-1)
        return dp[a][b][c][last];

    if(last!=1){
        suma = solve(a-1, b, c, 1);
        suma %= MOD;
    }
    if(last!=2){
        sumb = solve(a, b-1, c, 2);
        sumb %= MOD;
    }
    if(last!=3){
        sumc = solve(a, b, c-1, 3);
        sumc %= MOD;
    }
    dp[a][b][c][last] = suma + sumb + sumc;
    dp[a][b][c][last] %= MOD;
    return dp[a][b][c][last];
}

int main(){
    setIO();
    ll q, a, b, c;
    memset(dp, -1, sizeof dp);    
    for(int i=1; i<=3; i++)
        dp[0][0][0][i] = 1;
    dp[1][0][0][1] = dp[0][1][0][2] = dp[0][0][1][3] = 0;    
    solve(100, 100, 100, 0);
    cin >> q;
    while(q--){
        ll sum = 0;
        cin >> a >> b >> c;
        sum += solve(a-1, b, c, 1);
        sum %= MOD;
        sum += solve(a, b-1, c, 2);
        sum %= MOD;
        sum += solve(a, b, c-1, 3);
        sum %= MOD;
        cout << sum << "\n";
    }
    return 0;
}
/*
3
1 1 2
1 0 1
1 1 1
*/
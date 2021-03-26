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

const long long MOD = 1e9 + 7;

long long dp[100010];

int main(){
    setIO();
    long long i, n;
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    for(i=3; i<=n; i++){
        dp[i] = ((( (dp[i-1] % MOD) + (dp[i-2] % MOD))) % MOD) * (i - 1);
        dp[i] %= MOD;
    }
    cout << dp[n];
    return 0;
}
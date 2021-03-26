/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define MOD (int)9241

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int dp[110][110], qs[110][110];

int main(){
    setIO();
    int q, n, k;
    dp[0][0] = 1;
    for(int i=1; i<=100; i++){
        for(int j=0; j<=100; j++){
            /// Vertical
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            /// Horizontal
            if(i-2 >= 0){
                dp[i][j] += dp[i-2][j];
                dp[i][j] %= MOD;
            }
            /// Square
            if(i-2 >= 0 && j-1 >= 0){
                dp[i][j] += dp[i-2][j-1];
                dp[i][j] %= MOD;
            }
            /// Different L
            if(j>=2){
                for(int k=3; k<=i; k+=2){
                    dp[i][j] += dp[i-k][j-2] * 2;
                    dp[i][j] %= MOD;
                }
            /// Same L
                for(int k=4; k<=i; k+=2){
                    dp[i][j] += dp[i-k][j-2] * 2;
                    dp[i][j] %= MOD;
                }
            }
            qs[i][j] = dp[i][j];
            if(j>=1){
                qs[i][j] += qs[i][j-1];
                qs[i][j] %= MOD;
            }
        }
    }
    cin >> q;
    while(q--){
        cin >> n >> k;
        cout << qs[n][k] % MOD << "\n";
    }
    return 0;
}
/*
3
3 0
3 1
3 2
*/
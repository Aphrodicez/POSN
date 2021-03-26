/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define fi(a, b) for(int i=a; i<=b; i++)

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int qs[100010], dp[100010][110];

int main(){
    setIO();
    int n, k, p;
    cin >> n >> k >> p;
    for(int i = 1; i<=n; i++){
        cin >> qs[i];
        qs[i] += qs[i-1];
    }
    if(n <= k + p){
        cout << qs[n];
        return 0;
    }
    for(int i = p; i<=n; i++){
        for(int j = 1; j<=k; j++){
            dp[i][j] = qs[i] - qs[i-p] + dp[i-p][j-1];
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
/*
9 3 2
2 5 1 9 1 7 3 4 5 
*/
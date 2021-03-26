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

string s, rs;

int dp[2][5010];

int main(){
    setIO();
    int n, i, j;
    cin >> n;
    cin >> s;
    rs = s;
    reverse(rs.begin(), rs.end());
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(s[i-1]==rs[j-1]){
                dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
            }    
            else
                dp[i%2][j] = max(dp[(i+1) % 2][j], dp[i%2][j-1]);
        }
    }
    cout << n - dp[n%2][n];
    return 0;
}
/*
5
Ab3bd
*/
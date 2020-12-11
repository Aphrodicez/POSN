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

int dp[510][510];

int main(){
    setIO();
    ll i, j, k, l, x, y, q;
    for(i=0; i<=33; i++){
        for(j=0; j<=33; j++){
            if(i+j==0)
                continue;
            for(k = 500; k>=i; k--){
                for(l = 500; l>=j; l--){
                    dp[k][l] = max(dp[k][l], dp[k-i][l-j] + 1);
                }
            }
        }
    }
    cin >> q;
    while(q--){
        cin >> x >> y;
        cout << dp[x][y] << "\n";
    }
    return 0;
}
/*
4
2 0
3 0
3 1
4 5
*/
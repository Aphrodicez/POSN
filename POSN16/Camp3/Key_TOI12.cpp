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

int i, j, r, c, q;
int dp[1010][1010];
char a[1010], b[1010], w[2010];

int main(){
    setIO();
    scanf(" %s %s", a+1, b+1);
    r = strlen(a+1);
    c = strlen(b+1);
    scanf("%d", &q);
    while(q--){
        scanf(" %s", w+1);
        dp[0][0] = 1;
        for(i=1; i<=r; i++){
            if(dp[i-1][0] && a[i]==w[i]){
                dp[i][0] = 1;
            }
        }
        for(j=1; j<=c; j++){
            if(dp[0][j-1] && b[j]==w[j])
                dp[0][j] = 1;
        }
        for(i=1; i<=r; i++){
            for(j=1; j<=c; j++){
                if(dp[i][j-1] && b[j] == w[i+j])
                    dp[i][j] = 1;
                else if(dp[i-1][j] && a[i] == w[i+j])
                    dp[i][j] = 1;
            }
        }
        if(dp[r][c])
            cout << "Yes\n";
        else
            cout << "No\n";
        memset(dp, 0, sizeof dp);
    }
    return 0;
}
/*
BAB
AB
4
BAABB
BABAB
ABBAB
BBABA
*/

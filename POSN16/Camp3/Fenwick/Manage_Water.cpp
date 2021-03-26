/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll opr, n, r, c, r2, c2, val;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

//int dp[2010][2010];

int dp[2010][2010], sum, i, j;

int main(){
    setIO();
    cin >> opr >> n;
    while(1){
        cin >> opr;
        sum = 0;
        if(opr==1){
            cin >> c >> r >> val;
            r++, c++;
            for(i = r; i <= n; i += i & -i){
                for(j = c; j <= n; j += j & -j){
                    dp[i][j] += val;
                }
            }
        }
        else if(opr==2){
            cin >> c >> r >> c2 >> r2;
            c++, r++, c2++, r2++;
            j = c2;
            for(i = r2; i > 0; i -= i & -i){
                for(j = c2; j > 0; j -= j & -j){
                    sum += dp[i][j];
                }
            }
            for(i = r-1; i > 0; i -= i & -i){
                for(j=c2;j>0;j-=j&-j)
                    sum -= dp[i][j];
            }
            i = r;
            for(j = c-1; j > 0; j -= j & -j){
                for(i = r2; i > 0; i -= i & -i)
                sum -= dp[i][j];
            }
            for(i = r - 1; i > 0; i -= i & -i){
                for(j = c - 1; j > 0; j -= j & -j){
                    sum += dp[i][j];
                }
            }
            cout << sum << "\n";
        }
        else
            return 0;
    }
    return 0;
}
/*
0 4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
3
*/

/*
    TASK    : Observatory_TOI11
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

ll i, j, r, c, k, num, sum, ans = -2e12;

ll lTri[2010][2010], rTri[2010][2010], lqs[2010][2010], rqs[2010][2010];

int main(){
    setIO();
    cin >> r >> c >> k;
    for(i=1; i<=r; i++){
        for(j=1; j<=c; j++){
            //scanf("%lld", &num);
            cin >> num;
            lqs[i][j] = num;
            lqs[i][j] += lqs[i-1][j] + lqs[i][j-1] - lqs[i-1][j-1];
            lTri[i][j] = lTri[i-1][j-1] + lqs[i][j] - lqs[i-1][j];
            rqs[i][j] = num;
            if(i < k || j < k)
                continue;
            sum = lTri[i][j] - lTri[i-k][j-k] - lqs[i][j-k] + lqs[i-k][j-k];
            ans = max(ans, sum);
        }
    }
    for(i=1; i<=r; i++){
        for(j=c; j>=1; j--){
            rqs[i][j] += rqs[i-1][j] + rqs[i][j+1] - rqs[i-1][j+1];
            rTri[i][j] = rTri[i-1][j+1] + rqs[i][j] - rqs[i-1][j];
            if(i < k || j + k > c + 1)
                continue;
            sum = rTri[i][j] - rTri[i-k][j+k] - rqs[i][j+k] + rqs[i-k][j+k];
            ans = max(ans, sum);
        }
    }
    //printf("%lld", ans);
    cout << ans;
    return 0;
}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/
/*
6 7 4
-99 -99 -99 -99 -99 -99 -99
-99 -5 -99 -99 -99 -99 -99
-99 -5 -5 -99 -99 -99 -4
-99 -5 -5 -5 -99 -5 -6
-99 -5 -5 -5 -2 -5 -6
-99 -99 -99 -5 -5 -5 -4
*/

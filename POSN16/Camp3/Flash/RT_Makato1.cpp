/*
    TASK    : RT_Makato
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

int dp[100010];

int main(){
    setIO();
    int n, q, l, r;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> dp[i];
        dp[i] ^= dp[i-1];
    }
    while(q--){
        int ans;
        cin >> l >> r;
        ans = dp[r] ^ dp[l-1];
        cout << ans << "\n";
    }
    return 0;
}
/*
5 5
2 6 2 9 1
5 5
1 5
2 3
4 5
2 4
*/
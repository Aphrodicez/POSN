/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Longest Increasing Subsequence
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 2e3 + 10;
const int M = 2e5 + 10;

char a[N], b[N], ans[N];

int dp[N][N], path[N][N];

void solve() {
    int lena, lenb;
    scanf(" %s", a + 1);
    scanf(" %s", b + 1);
    lena = strlen(a + 1);
    lenb = strlen(b + 1);
    for(int i = 1; i <= lena; i++){
        for(int j = 1; j <= lenb; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = 3;
                continue;
            }
            dp[i][j] = max({dp[i][j - 1], dp[i - 1][j]});
            if(dp[i - 1][j] >= dp[i][j - 1]){
                path[i][j] = 1;
                continue;
            }
            path[i][j] = 2;
        }
    }
    printf("%d\n", dp[lena][lenb]);    
    if(!dp[lena][lenb]){
        printf("No Roma word\n");
        return ;
    }
    int i = lena, j = lenb, it = 0;
    while(i >= 1 && j >= 1){
        if(path[i][j] == 1){
            i--;
            continue;
        }
        if(path[i][j] == 2){
            j--;
            continue;
        }
        ans[it++] = a[i];
        i--;
        j--;
    }
    for(int i = it - 1; i >= 0; i--)
        printf("%c", ans[i]);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
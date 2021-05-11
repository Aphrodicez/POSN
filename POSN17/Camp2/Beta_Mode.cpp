/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Longest Common Substring
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e4 + 10;
const int M = 1e5 + 10;

char a[N], b[N];

int dp[2][N];

void solve() {
    int lena, lenb, mx = -1, en;
    scanf(" %s", a + 1);
    scanf(" %s", b + 1);
    lena = strlen(a + 1);
    lenb = strlen(b + 1);
    for(int i = 1; i <= lena; i++){
        for(int j = 1; j <= lenb; j++){
            if(a[i] == b[j]){
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
            }
            else
                dp[i % 2][j] = 0;                
            if(dp[i % 2][j] > mx){
                mx = dp[i % 2][j];
                en = j;
            }
        }
    }
    for(int i = en - mx + 1; i <= en; i++){
        printf("%c", b[i]);
    }
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
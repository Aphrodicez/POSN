/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Matrix Chain Multiplication
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 2e1 + 10;
const int M = 2e5 + 10;

int row[N], col[N], dp[N][N], path[N][N];

int multiplycnt(int l, int mid, int r){
    return row[l] * col[mid] * col[r];
}

void print(int l, int r){
    if(l == r){
        printf("A%d", l);
        return ;
    }
    int mid = path[l][r];
    printf("(");
    print(l, mid);
    printf(" x ");
    print(mid + 1, r);
    printf(")");
}

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &row[i], &col[i]);
    }
    for(int sz = 1; sz <= n - 1; sz++){
        for(int start = 1; start + sz <= n; start++){
            int l = start, r = start + sz;
            dp[l][r] = 1e9;
            for(int mid = l; mid <= r - 1; mid++){
                if(dp[l][mid] + dp[mid + 1][r] + multiplycnt(l, mid, r) < dp[l][r]){
                    dp[l][r] = dp[l][mid] + dp[mid + 1][r] + multiplycnt(l, mid, r);
                    path[l][r] = mid;
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);
    print(1, n);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
5 10
10 20
20 35
*/
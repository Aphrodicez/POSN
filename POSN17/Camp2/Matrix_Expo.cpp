/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Divide And Conquer
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

using i64 = long long;

#define v(a) vector <a> 

const i64 N = 1e1 + 10;
const i64 M = 2e5 + 10;

i64 n;

v(v(i64)) a, tmp;

v(v(i64))* multiply(v(v(i64)) *a, v(v(i64)) *b, i64 c){
    v(v(i64)) *tmp;
    (*tmp).resize(n + 1);
    for(i64 i = 1; i <= n; i++){
        (*tmp)[i].resize(n + 1);
        for(i64 j = 1; j <= n; j++){
            i64 sum = 0ll;
            for(i64 k = 1; k <= n; k++){
                i64 numa = (*a)[i][k] % c;
                i64 numb = (*b)[k][j] % c;
                sum += (numa * numb) % c;
            }
            (*tmp)[i][j] = sum;
        }
    }
    return tmp;
} 

v(v(i64))* modOfPower(i64 b, i64 c){
    if(b == 1)
        return &a;
    tmp = *modOfPower(b / 2, c);
    tmp = *multiply(&tmp, &tmp, c);
    if(b % 2)
        tmp = multiply(&tmp, &a, c);
    return tmp;
}

void solve() {
    i64 b, c;
    scanf("%d", &n);
    a.resize(n + 1);
    for(i64 i = 1; i <= n; i++){
        a[i].resize(n + 1);
        for(i64 j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &b, &c);
    v(v(int)) ans = *modOfPower(b, c);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
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
/*
2
5 8
21 6
2 100
*/
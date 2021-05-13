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

using i64 = long long;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

i64 lis[N], qs[N];

void solve() {
    memset(qs, 0, sizeof qs);
    memset(lis, 0, sizeof lis);
    i64 n;
    scanf("%lld", &n);
    for(i64 i = 1; i <= n; i++){
        scanf("%lld", &qs[i]);
    }
    for(i64 i = 1; i <= n; i++){
        qs[i] += qs[i - 1];
    }
    i64 cnt = 0, lb;
    for(i64 i = 1; i <= n; i++){
        if(qs[i] <= 0)
            continue;
        lb = lower_bound(lis, lis + cnt, qs[i]) - lis;
        lis[lb] = qs[i];
        if(lb == cnt){
            cnt++;
        }
    }
    printf("%lld\n", lb + 1);
}

int main() {
    i64 q;
    scanf("%lld", &q);
    while(q--){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4
5
10 -2 -30 40 -1
12
10 -2 -10 6 9 7 -5 -2 1 2 3 4
3
5 10 -14
3
-14 10 5
*/
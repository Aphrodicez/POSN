/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bitmasking
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int N = 1e4 + 10;
const int K = 8;

i64 w[N], sum[N], mask[1 << K];

void solve() {
    i64 n, k, num;
    scanf("%lld %lld", &n, &k);
    for(i64 i = 1; i <= n; i++){
        scanf("%lld", &w[i]);
        for(i64 j = 0; j < k; j++){
            scanf("%lld", &num);
            if(num)
                sum[i] |= (1 << j);
        }
    }
    for(i64 i = 1; i <= (1 << k) - 1; i++){
        mask[i] = 1e18;
    }
    for(i64 i = 0; i <= (1 << k) - 1; i++){
        if(mask[i] == 1e18)
            continue;
        for(i64 j = 1; j <= n; j++){
            mask[i | sum[j]] = min(mask[i | sum[j]], mask[i] + w[j]);
        }
    }
    printf("%lld\n", mask[(1 << k) - 1]);
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
5 3
10 1 0 1
30 0 1 1
5 1 0 0
4 0 0 1
150 1 1 1
*/
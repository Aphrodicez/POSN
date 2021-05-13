/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Divide And Conquer
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

v(int) rootval;

v(int) multiply(v(int) a, v(int) b, int k) {
    v(int) tmp(4, 0);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int sum = 0;
            sum += a[i] * b[j];
            sum %= k;
            int root = rootval[i] * rootval[j];
            for(int it = 3; it >= 0; it--){
                int sq = rootval[it] * rootval[it];
                if( (root % sq == 0) && (root / sq) ){
                    sum *= rootval[it];
                    sum %= k;
                    root /= sq;
                }
            }
            for(int it = 3; it >= 0; it--){
                if(root == rootval[it]){
                    tmp[it] += sum;
                    tmp[it] %= k;
                }
            }
        }
    }
    return tmp;
}

v(int) find_root(v(int) base, int n, int k){
    if(n == 1)
        return base;
    v(int) tmp = find_root(base, n / 2, k);
    tmp = multiply(tmp, tmp, k);
    if(n % 2)
        tmp = multiply(tmp, base, k);
    return tmp;
}

void solve() {
    int a, b, c, n, k;
    scanf("%d %d %d %d %d", &a, &b, &c, &n, &k);
    v(int) ans = find_root({a % k, b % k, c % k, 0}, n, k);
    for(int i = 0; i < 4; i++)
        printf("%d ", ans[i]);
}

int main() {
    int q;
    scanf("%d", &q);
    rootval = {1, 2, 3, 6};
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
1
1 1 1 2 10
*/
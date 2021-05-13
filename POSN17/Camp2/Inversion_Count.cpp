/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Inversion Count
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

using i64 = long long;

const i64 N = 1e5 + 10;
const i64 M = 2e5 + 10;

i64 a[N], b[N];
i64 ans = 0;

void mergeSort(i64 l, i64 r){
    if(l >= r)
        return ;
    i64 mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    i64 i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(a[j] < a[i]){
            b[k++] = a[j++];
            ans += mid - i + 1;
        }
        else{
            b[k++] = a[i++];
        }
    }
    while(i <= mid)
        b[k++] = a[i++];
    while(j <= r)
        b[k++] = a[j++];
    for(i64 i = l; i <= r; i++)
        a[i] = b[i];
}

void solve() {
    i64 n;
    scanf("%lld", &n);
    for(i64 i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    mergeSort(1, n);
    printf("%lld\n", ans);
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
5
2 4 1 3 5
*/
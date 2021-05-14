/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Merge Sort
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

struct A{
    i64 a, b;
};

bool cmpb(A a, A b){
    return a.b < b.b;
}

const int N = 2e5 + 10;
const int M = 2e5 + 10;

A a[N], tmp[N];
i64 qs[N];

i64 sum = 0;

void mergeSort(i64 l, i64 r){
    if(l >= r)
        return ;
    i64 mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    i64 i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(a[i].a > a[j].a){            
            sum += qs[mid] - qs[i - 1] + (a[j].a * (mid - i + 1));
            tmp[k++] = a[j++];
        }
        else{
            tmp[k++] = a[i++];
        }
    }
    while(i <= mid){
        tmp[k++] = a[i++];
    }
    while(j <= r){
        tmp[k++] = a[j++];
    }
    for(i64 i = l; i <= r; i++){
        a[i] = tmp[i];
    }
    for(i64 i = l; i <= r; i++){
        qs[i] = qs[i - 1] + a[i].a;
    }
}

void solve() {
    i64 n;
    scanf("%lld", &n);
    for(i64 i = 1; i <= n; i++){
        scanf("%lld %lld", &a[i].a, &a[i].b);
    }
    sort(a + 1, a + 1 + n, cmpb);
    for(i64 i = 1; i <= n; i++){
        qs[i] = qs[i - 1] + a[i].a;
    }
    mergeSort(1, n);
    printf("%lld\n", sum);
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
6
2 1 7 6 9 3 18 4 3 2 5 5

4
1 4 3 2 2 3 7 1
*/
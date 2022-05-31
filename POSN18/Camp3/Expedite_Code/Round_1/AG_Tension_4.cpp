/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Math + Binary Search
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

long long sqrt(long long n) {
    long long l = 0, r = 2e9;
    while(l < r) {
        long long mid = l + (r - l + 1) / 2;
        if(mid * mid > n)
            r = mid - 1;
        else
            l = mid;
    }
    return l; 
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    while(q--) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", sqrt(r) + sqrt(r / 2) - sqrt(l - 1) - sqrt((l - 1) / 2));
    }
    return 0;
}

/*
7 3
1 2
4 7
3 5
*/
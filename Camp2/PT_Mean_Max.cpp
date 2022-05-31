/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Binary Search + Math + Prefix Sum
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 3e5 + 10;

double a[MaxN];

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    double lb = 0, rb = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        rb = max(rb, a[i]);
    }
    while(rb - lb > 1e-6) {
        double midb = (lb + rb + 1e-6) / 2;
        bool ch = false;
        double mn = 0, suml = 0, sumr = 0;
        int l = 0;
        for(int r = 1; r <= n; r++) {
            sumr += a[r] - midb;
            if(r < k)
                continue;
            mn = min(mn, suml);
            if(sumr - mn >= 0) {
                ch = true;
                break;
            }
            l++;
            suml += a[l] - midb;
        }
        if(ch)
            lb = midb;
        else
            rb = midb - 1e-6;
    }
    printf("%.1lf\n", lb);
}

int main() {
    int q = 1;
    //scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/*
4 2
4 3 4 2

6 3
6 3 1 2 1 7
*/
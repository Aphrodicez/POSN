/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Binary Search [ Lower Bound ] + Quicksum 1D
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;
int qs[MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int a = 0, b = 0;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &qs[i]);
            qs[i] = qs[i] + qs[i - 1];
        }
        if(qs[n] % 2) {
            printf("NO\n");
            continue;
        }
        for(int i = 1; i <= n; i++) {
            if(qs[i] == qs[n] / 2) {
                a = i;
                break;
            }
        }
        if(a) {
            printf("%d\n", a);
            continue;
        }
        for(int i = 1; i <= n; i++) {
            int lb = lower_bound(qs + 1, (qs + 1) + n, qs[i] + qs[n] / 2) - qs;
            if(qs[lb] - qs[i] == qs[n] / 2) {
                a = i;
                b = lb;
                break;
            }
        }
        if(a && b) {
            printf("%d %d\n", a, b);
            continue;
        }
        printf("NO\n");
    }
    return 0;
}

/*
3
8
3 1 2 1 1 2 1 1
8
2 1 3 1 5 4 1 5
8
10 20 3 40 5 7 15 2
*/
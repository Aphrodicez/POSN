/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Binary Search + Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 10;

int a[MaxN];
int sorted[MaxN];

int main() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + 1 + n);
    int l = 1, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        int last = -1e9;
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] > sorted[mid] && i - last + 1 > p) {
                cnt++;
                last = i;
            }
            if(cnt > k)
                break;
        }
        if(cnt > k)
            l = mid + 1;
        else
            r = mid;
    }
    printf("%d\n", sorted[l]);
    return 0;
}

/*
10 2 2
51
42
54
31
12
57
11
51
85
36
*/
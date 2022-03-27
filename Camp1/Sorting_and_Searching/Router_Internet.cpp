/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Binary Search + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

int a[MaxN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
        a[i] *= 2;
    }
    sort(a + 1, (a + 1) + m);
    int l = 0, r = 2e6;
    while(l < r) {
        int mid = (l + r) / 2;
        int cnt = 0, last = -(2e6 + 10);
        for(int i = 1; i <= m; i++) {
            if(abs(a[i] - last) > mid) {
                cnt++;
                last = a[i] + mid;
            }
            if(cnt > n)
                break;
        }
        if(cnt > n)
            l = mid + 1;
        else
            r = mid;
    }
    printf("%.1lf\n", ((double)l) / 2);
    return 0;
}

/*
2 3
1 3 10
*/
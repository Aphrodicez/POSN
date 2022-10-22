#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 10;

int a[MaxN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int l = 1, r = 2e9;
    while(l < r) {
        int mid = l + (r - l + 1) / 2; // (l + r + 1) / 2
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += max(0, a[i] - mid);
            if(sum >= m)
                break;
        }
        if(sum >= m)
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d", l);
    return 0;
}

/*
4 7
20 15 10 17

5 20
4 42 40 26 46
*/
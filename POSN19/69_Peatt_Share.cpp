#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

int a[MaxN];
int qs[MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        
        for(int i = 1; i <= n; i++)
            qs[i] = qs[i - 1] + a[i];

        if(qs[n] % 2) {
            printf("NO\n");
            continue;
        }

        bool ch = false;
        // 1
        for(int r = 1; r <= n && !ch; r++) {
            if(qs[r] == qs[n] / 2) {
                printf("%d\n", r);
                ch = true;
                break;
            }
        }
        
        // 2
        for(int l = 1; l <= n && !ch; l++) {
            int r = lower_bound(qs + 1, (qs + 1) + n, qs[l] + qs[n] / 2) - qs;
            if(qs[r] - qs[l] == qs[n] / 2) {
                printf("%d %d\n", l, r);
                ch = true;
                break;
            }
        }
        if(!ch)
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
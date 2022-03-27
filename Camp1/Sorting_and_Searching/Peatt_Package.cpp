/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Binary Search + Counting Sort
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;
int w[MaxN], c[MaxN];
int mark[MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int l = 0, r = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &w[i], &c[i]);
            l = max(l, w[i]);
            sum += w[i];
        }
        r = sum + 1;
        while(l < r) {
            memset(mark, 0, sizeof (mark));
            int mid = (l + r) / 2;
            int sum = 0, cnt = 1;
            for(int i = 1; i <= n; i++) {
                if(sum + w[i] > mid || mark[c[i]] == cnt) {
                    sum = 0;
                    cnt++;
                }
                if(cnt > k)
                    break;
                sum += w[i];
                mark[c[i]] = cnt;
            }
            if(cnt > k)
                l = mid + 1;
            else
                r = mid;
        }
        if(l > sum)
            printf("-1\n");
        else
            printf("%d\n", l);
    }
    return 0;
}

/*
2
5 3
10 1
10 2
40 1
30 3
30 4
5 2
10 1
10 2
40 1
30 3
30 1
*/
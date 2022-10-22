#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

int w[MaxN], c[MaxN];
int cnt[MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int MaxW = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &w[i], &c[i]);
            MaxW = max(MaxW, w[i]);
        }
        int l = MaxW, r = 1e8;
        while(l < r) {
            memset(cnt, 0, sizeof (cnt));
            int mid = l + (r - l) / 2;
            int sum = 0;
            int cnt_group = 1;
            for(int i = 1; i <= n; i++) {
                if(sum + w[i] > mid || cnt[c[i]] == cnt_group) {
                    sum = w[i];
                    cnt_group++;
                    cnt[c[i]] = cnt_group;
                    continue;
                }
                sum += w[i];
                cnt[c[i]] = cnt_group;
            }
            if(cnt_group <= k)
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l == 1e8 ? -1 : l);
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
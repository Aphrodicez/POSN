/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Recursion + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 20 + 10;

long long a[MaxN];

int ch = 0;

long long dfs(int k, long long w) {
    if(ch)
        return -1;
    if(w <= 0)
        return ch = -1;
    if(k == 1)
        return w;
    long long mid = (2 * w - a[k - 1] + 1);
    return dfs(k - 1, mid / 2) + dfs(k - 1, mid / 2 + (mid & 1));
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        ch = 0;
        int k;
        long long w;
        scanf("%d %lld", &k, &w);
        for(int i = 1; i <= k - 1; i++) {
            scanf("%lld", &a[i]);
        }
        long long ans = dfs(k, w);
        printf("%lld\n", ch == -1 ? -1ll : ans);
    }
    return 0;
}

/*
3
2 1
1
3 10
10 10
3 10
9 9
*/
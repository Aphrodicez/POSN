/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Binary Search + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e3 + 10;

long long a[MaxN];

long long diff(long long lvl, int type) {
    if(lvl < 0)
        return 0;
    if(type)
        return max(0ll, lvl * lvl);
    return max(0ll, lvl * (lvl + 1));
}

void solve() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    long long l = 0, r = 1e9;
    while(l < r) {
        long long mid = l + (r - l) / 2;
        long long sum = (mid + 1) * (mid + 1);
        for(int i = 2; i <= n; i++) {
            if(a[i] == a[i - 1])
                continue;
            long long dis = (a[i] - a[i - 1] - 1);
            sum -= diff(mid - (dis / 2), dis % 2);
            sum += (mid + 1) * (mid + 1);
            if(sum >= k)
                break;
        }
        if(sum >= k)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld\n", l);
}

int main() {
    int q = 1;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

/*
3
3 10
0 5 6
3 30
0 6 5
2 10
0 0
*/
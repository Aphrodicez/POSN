/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Binary Search + Observation
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

set <long long> field;

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    long long ans = 0;
    long long sum = 0;
    long long mx = 0;
    for(int i = 1; i <= n; i++) {
        long long val;
        scanf("%lld", &val);
        sum = (sum + val) % m;
        mx = max(mx, sum);
        field.insert(sum);
        if(sum == mx) {
            ans = max(ans, sum);
            continue;
        }
        auto it = field.upper_bound(sum);
        ans = max(ans, (sum - *it + m) % m);
    }
    printf("%lld\n", ans);
    return 0;
}

/*
5 7
3 3 9 9 5
*/
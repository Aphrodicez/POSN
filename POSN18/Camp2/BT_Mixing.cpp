/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        long long last;
        scanf("%lld", &last);
        for(int i = 2; i <= n; i++) {
            long long val;
            scanf("%lld", &val);
            ans += max(last, val);
            last = val;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*

*/
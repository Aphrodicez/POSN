/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

map <long long, int> mp;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        mp.clear();
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            long long val;
            scanf("%lld", &val);
            mp[val]++;
        }
        long long ans = 0;
        long long mx = 0;
        for(auto x : mp) {
            if(x.second & 1ll) {
                ans++;
                mx = x.first;
            }
            if(x.second <= 1)
                continue;
            mp[x.first + 1] += x.second >> 1ll;
            mx = x.first;
        }
        ans = mx - ans + 1;
        printf("%lld\n", ans);
    }
    return 0;
}

/*
3
3
5 3 3
4
3 5 4 2
4
0 0 0 0
*/
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
        int cnt[2] = {0, 0};
        for(int i = 1; i <= n; i++) {
            int val;
            scanf("%d", &val);
            if(val)
                cnt[i % 2]++;
        }
        if(n % 2 || abs(cnt[0] - cnt[1]) <= 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

/*
2
18 0 0 1 0 1 1 1 1 0 1 0 0 1 0 0 0 0 1
14 1 1 0 0 1 1 1 0 0 1 1 0 1 0
*/
/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
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
        int ans = 0;
        int sum = 0, mx = 0;
        for(int i = 1; i <= n; i++) {
            int val;
            scanf("%d", &val);
            if(i % 2)
                val *= -1;
            ans += val;
            sum += val;
            mx = max(mx, sum);
            sum = max(sum, 0);
        }
        printf("%d\n", ans - 2 * mx);
    }
    return 0;
}

/*
2
3
3 4 8
4
3 1 1 5
*/
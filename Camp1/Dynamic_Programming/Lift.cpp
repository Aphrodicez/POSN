  /*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

bool dp[45010];

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        sum += val;
        for(int j = 45000; j - val >= 0; j--) {
            if(dp[j - val])
                dp[j] = 1;
        }
    }
    int ans1, ans2;
    int mn = sum + 1;
    for(int i = 0; i <= sum / 2; i++) {
        if(dp[i]) {
            if(abs(sum - 2 * i) < mn) {
                mn = abs(sum - 2 * i);
                ans1 = i, ans2 = sum - i;
            }
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}

/*
3
100
90
200
*/
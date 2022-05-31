/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Counting Sort + Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 10;

int cnt[MaxN];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        if(cnt[val + 1])
            cnt[val + 1]--;
        else
            ans++;
        cnt[val]++;
    }
    printf("%d\n", ans);
    return 0;
}

/*

*/
#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

int dp[MaxN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        dp[l] += 1;
        dp[r + 1] -= 1; // r + 1 อาจเท่ากับ n + 1
    }
    // Quicksum ครั้งเดียวหลังจากจบทุกการ update แล้วเท่านั้น [ห้าม Quicksum แล้ว update ต่อ]
    for(int i = 1; i <= n + 1; i++) { // ควรวนถึง dp[n + 1] เนื่องจาก dp[n + 1] อาจยังมีค่าติดลบอยู่
        dp[i] += dp[i - 1]; // Quicksum 1 -> MaxR
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int idx;
        scanf("%d", &idx);
        printf("%d\n", dp[idx]);
    }
    return 0;
}

/*
5 2
1 3
2 4
3
3
5
4
*/
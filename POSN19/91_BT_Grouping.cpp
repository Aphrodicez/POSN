#include <bits/stdc++.h>
using namespace std;

int a[100010];
int cost[100010]; // a[i - 1] - a[i];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if(i > 1)
                cost[i - 1] = a[i] - a[i - 1];
        }
        sort(cost + 1, (cost + 1) + (n - 1)); // มี n - 1 cost
        int cnt_group = n;
        int i = 1;
        int ans = 0;
        while(cnt_group > k) {
            ans += cost[i];
            i++;
            cnt_group--;
            // ใช้ cost เชื่อมกลุ่ม 1 ครั้ง กลุ่มหายไป 1 กลุ่ม
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
1
9 3
2 2 4 5 6 8 10 11 17
*/
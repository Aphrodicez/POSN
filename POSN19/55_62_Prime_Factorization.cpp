#include <bits/stdc++.h>
using namespace std;

int ans[40];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        int sq = sqrt(n);
        for(int i = 2; i <= sq; i++) {
            while(n % i == 0) {
                cnt++;
                ans[cnt] = i;
                n /= i;
            }
        }
        if(n > 1) {
            cnt++;
            ans[cnt] = n;
        }
        sort(ans + 1, (ans + 1) + cnt);
        for(int i = 1; i <= cnt; i++) {
            printf("%d", ans[i]);
            if(i != cnt)
                printf(" x ");
        }
        printf("\n");
    }
    return 0;
}

/*
3
100
17
18
*/
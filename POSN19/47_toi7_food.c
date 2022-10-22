#include <stdio.h>

int ans[10];
int mark[10];
int unavailable[10];

int n;

void permu(int state) {
    int i;
    if(state == n) {
        for(i = 0; i < n; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for(i = 1; i <= n; i++) {
        if(!state && unavailable[i]) // เลขที่ถูกติ๊กว่า unavailable ไม่สามารถเป็นตัวแรกได้
            continue;
        if(mark[i])
            continue;
        mark[i] = 1;
        ans[state] = i;
        permu(state + 1);
        mark[i] = 0;
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    int i;
    for(i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        unavailable[x] = 1; // ไม่สามารถใช้เลข x เป็นตัวแรกของคำตอบได้
    }
    permu(0);
    return 0;
}
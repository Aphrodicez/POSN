#include <stdio.h>

int ans[15 + 10];

int n;

void permu(int state, int last) {
    int i;
    if(state == n) {
        for(i = 0; i < n; i++)
            printf("%d", ans[i]);
        printf("\n");
        return ;
    }
    // Bit Binary ตัวก่อนหน้า + Bit Binary ตัวปัจจุบัน
    ans[state] = (last + 0) % 2;
    permu(state + 1, 0);
    // เลือก permu 0 ก่อน permu 1
    ans[state] = (last + 1) % 2;
    permu(state + 1, 1);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        permu(0, 0);
    }
    return 0;
}
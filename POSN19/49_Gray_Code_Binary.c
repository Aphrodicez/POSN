#include <stdio.h>

int ans[15 + 10];

int n;

void permu(int state) {
    int i;
    if(state == n) {
        // Permu Binary มาก่อน
        printf("%d", ans[0]);
        for(i = 1; i < n; i++) // จากนั้นนำมาแปลงเป็น Gray Code
            printf(" %d", (ans[i - 1] + ans[i]) % 2);
        return ;
    }
    ans[state] = 0;
    permu(state + 1);
    ans[state] = 1;
    permu(state + 1);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        permu(0);
    }
    return 0;
}
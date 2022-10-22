#include <stdio.h>

char ans[210]; // แข่งกันต่อได้มากสุด 2k - 1 ครั้ง

int k;

void permu(int state, int a, int b) {
    int i;
    if(a == k || b == k) {
        for(i = 0; i < state; i++)
            printf("%c ", ans[i]);
        printf("\n");
        return;
    }
    ans[state] = 'W'; // ให้คนแรกชนะก่อน
    permu(state + 1, a + 1, b);
    ans[state] = 'L'; // หลังจาก return กลับมา เปลี่ยนให้คนที่สองชนะแทน
    permu(state + 1, a, b + 1);    
}

int main() {
    int a, b;
    scanf("%d %d %d", &k, &a, &b);
    permu(0, a, b);
    return 0;
}
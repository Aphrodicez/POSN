#include <stdio.h>

int ans[20];
int mark[20];

int cnt;

int n, r, k;

void permu(int state) {
    int i;
    if(state == r) { // Base Case คือ หยิบเลขครบ r ตัวแล้ว
        cnt++;
        if(cnt == k) {
            for(i = 0; i < r; i++)
                printf("%d ", ans[i]);
            exit(0); // return 0; จบโปรแกรมจากฟังก์ชัน
        }
        return ;
    }
    for(i = 1; i <= n; i++) {
        if(mark[i]) // ข้ามเลขที่หยิบใช้ไปแล้ว
            continue;
        mark[i] = 1; // mark ว่าหยิบเลขนี้ไปแล้ว
        ans[state] = i; // หยิบเลขนี้ไปใส่ในคำตอบช่องที่ state
        permu(state + 1); // เล่น state ถัดไป
        mark[i] = 0; // backtrack ยกเลิกการ mark ว่าหยิบเลขนี้ไปแล้ว
    }
}

int main() {
    scanf("%d %d %d", &n, &r, &k);
    permu(0);
    return 0;
}
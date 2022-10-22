#include <stdio.h>

// N E S W
const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};

int a[30][30];

int n;

int ans = -6; // ค่าต่ำสุดที่เป็นไปได้ คือ -5

void play(int i, int j) {
    if(ans < a[i][j])
        ans = a[i][j];
    
    int k;
    for(k = 0; k < 4; k++) {
        int ii = i + d4i[k]; // i ของตำแหน่งที่จะไป
        int jj = j + d4j[k]; // j ของตำแหน่งที่จะไป
        if(ii < 1 || jj < 1 || ii > n || jj > n) // เช็คขอบก่อนทุกเงื่อนไข
            continue;
        if(a[ii][jj] <= a[i][j]) // อุณหภูมิไม่เพิ่มขึ้นจากช่องปัจจุบัน
            continue;
        play(ii, jj);
    }
}

int main() {
    scanf("%d", &n);
    int sti, stj;
    scanf("%d %d", &stj, &sti); // รับค่าจุดเริ่มต้น j [แกน x] และ i [แกน y]
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    play(sti, stj);
    printf("%d", ans);
    return 0;
}
#include <stdio.h>

char a[30][30]; // MaxRow = 20, MaxCol = 20

int cnt[30];

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // n = แถว, m = คอลัมน์
    int i, j;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    for(j = 1; j <= m; j++)
        scanf("%d", &cnt[j]);
    
    for(j = 1; j <= m; j++) {
        for(i = 1; i <= n && a[i][j] == '.'; i++); // วนไปหาแถวแรกที่ไม่ใช่ '.' หรือ เลยแถวสุดท้ายไป ( (พื้นดิน) a[i + 1][j] )
        
        i--; // ย้อนกลับไปหาแถวสุดท้ายที่เป็น '.'
        for(; i >= 1 && cnt[j] > 0; i--, cnt[j]--)
            a[i][j] = '#'; // ย้อนกลับขึ้นไปใส่หิน จนหินหมด หรือ เลยแถวบนสุดไป
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
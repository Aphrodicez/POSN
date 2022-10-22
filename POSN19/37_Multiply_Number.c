#include <stdio.h>
#include <string.h>

char a[5010]; // 10 ^ 5000
char b[5010]; // 10 ^ 5000
char ans[10010]; // 10 ^ 10000

int main() {
    scanf("%s", a);
    scanf("%s", b);

    int sign = 1;
    if(a[0] == '-') {
        sign *= -1;
        strcpy(a, a + 1);
    }
    if(b[0] == '-') {
        sign *= -1;
        strcpy(b, b + 1);
    }

    int lena = strlen(a);
    int lenb = strlen(b);
    int i, j;
    /*
        B (j)
         x
        A (i)
    */
    for(i = lena - 1; i >= 0; i--) {
        int lak = (lena - 1) - i; // หลักของเลขตัวล่างที่กำลังคูณ
        int tod = 0;
        for(j = lenb - 1; j >= 0; j--) {
            int val = (a[i] - '0') * (b[j] - '0') + tod;
            ans[lak] += val;
            tod = ans[lak] / 10;
            ans[lak] %= 10;
            lak++;
        }
        if(tod) {
            ans[lak] += tod;
            tod = ans[lak] / 10;
            ans[lak] %= 10;
            lak++;
        }
    }
    for(i = 10000; i >= 0 && ans[i] == 0; i--); // หาหลักแรกที่ไม่ใช่ 0

    if(i == -1) // คำตอบเป็นเลข 0
        printf("0");
    else {
        if(sign == -1) // ถ้าเป็นเลขลบ
            printf("-");
        for(; i >= 0; i--) // print ย้อนกลับ
            printf("%c", ans[i] + '0');
    }
    return 0;
}
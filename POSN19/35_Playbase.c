#include <stdio.h>
#include <string.h>

char str_a[27 + 10]; // 2 ^ 27 = 134,217,728
char str_b[27 + 10];
char str_sum[28 + 10]; // 2 ^ 28 = 268,435,456 [ a + b <= 200,000,000 ]

int main() {
    int base;
    scanf("%d", &base);
    int i;

    scanf(" %s", str_a);
    int a = 0;
    int lena = strlen(str_a);
    for(i = 0; i < lena; i++) {
        // การหารสังเคราะห์
        a *= base;
        if(isalpha(str_a[i]))
            a += str_a[i] - 'A' + 10; // 'B' - 'A' + 10 = 66 - 65 + 10 = 11
        else
            a += str_a[i] - '0'; // '4' - '0' = 52 - 48 = 4
    }
    scanf(" %s", str_b);
    int b = 0;
    int lenb = strlen(str_b);
    for(i = 0; i < lenb; i++) {
        b *= base;
        if(isalpha(str_b[i]))
            b += str_b[i] - 'A' + 10;
        else
            b += str_b[i] - '0';
    }
    int sum = a + b;
    printf("%d\n", sum);

    int cnt = 0;
    while(sum > 0) {
        int val = sum % base; // เศษจากการหารด้วยฐาน
        if(val >= 10)
            str_sum[cnt++] = val - 10 + 'A'; // str_sum[cnt] = val - 10 + 'A'; cnt++;
        else
            str_sum[cnt++] = val + '0'; // str_sum[cnt] = val + '0'; cnt++;
        sum /= base;
    }
    // ช่องสุดท้าย คือ str_sum[cnt - 1]
    for(i = cnt - 1; i >= 0; i--)
        printf("%c", str_sum[i]); // print ย้อนกลับ
    return 0;
}
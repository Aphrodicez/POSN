#include <stdio.h>

char a[1000 + 10][80 + 10];

int cnt; // ประกาศแบบ global เพื่อให้ฟังก์ชันอื่น ๆ เรียกใช้ได้

int r, c; // ประกาศแบบ global เพื่อให้ฟังก์ชันอื่น ๆ เรียกใช้ได้

void play(int i, int j) {
    cnt++; // นับจำนวน '*' ที่เดินผ่านในรอบปัจจุบัน
    a[i][j] = '.'; // ถม '*' ให้เป็น '.' เพื่อไม่วนมาช่องเดิมซ้ำ

    // ควรเช็คขอบ ก่อนเช็คทุกเงื่อนไขใน if
    if(i - 1 >= 1 && a[i - 1][j] == '*')
        play(i - 1, j); // N
    if(j + 1 <= c && a[i][j + 1] == '*')
        play(i, j + 1); // E
    if(i + 1 <= r && a[i + 1][j] == '*')
        play(i + 1, j); // S
    if(j - 1 >= 1 && a[i][j - 1] == '*')
        play(i, j - 1); // W
}

int main() {
    // รับจำนวนคอลัมน์ [ความกว้าง] และ จำนวนแถว [ความสูง] ตามลำดับ
    scanf("%d %d", &c, &r);
    int i, j;
    for(i = 1; i <= r; i++)
        scanf(" %s", a[i] + 1); // ให้ a[i] เริ่มที่ a[i][1] แทน a[i][0]
    
    int ans = 0;
    for(i = 1; i <= r; i++) {
        for(j = 1; j <= c; j++) {
            if(a[i][j] == '*') {
                cnt = 0; // รีเซ็ตค่า cnt ใหม่
                play(i, j);
                if(ans < cnt)
                    ans = cnt;
            }
        }
    }
    printf("%d", ans);
    return 0;
}

/*
10 5
..*.....**
.**..*****
.*...*....
..****....
..****....
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// หมุนตามเข็มนาฬิกา N -> NW
const int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

char a[35][35];
char s[25];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    int i, j;
    for(i = 0; i < r; i++)
        scanf(" %s", a[i]);
    int q;
    scanf("%d", &q);
    while(q--) {
        int ch = 0;
        scanf(" %s", s);
        int len = strlen(s);
        for(i = 0; i < r && !ch; i++) {
            for(j = 0; j < c && !ch; j++) {
                if(tolower(a[i][j]) == tolower(s[0])) { // พิมพ์ใหญ่หรือพิมพ์เล็กเป็นตัวเดียวกัน
                    int k = 0;
                    for(k = 0; k < 8 && !ch; k++) {
                        int ii = i;
                        int jj = j;
                        int state = 0; // ช่องปัจจุบันของ s
                        while(1) {
                            if(state == len - 1) { // ถ้าตัวสุดท้ายถูกต้อง
                                printf("%d %d\n", i, j);
                                ch = 1; // เจอคำตอบแล้ว
                                break;
                            }
                            // เคลื่อนที่ทิศ k ตลอดการเดินทาง
                            ii += di[k];
                            jj += dj[k];
                            if(ii < 0 || jj < 0 || ii > r - 1 || jj > c - 1) // เช็คขอบก่อนเช็คทุกเงื่อนไข
                                break;
                            if(tolower(a[ii][jj]) != tolower(s[state + 1])) // ถ้าตัวถัดไปไม่ตรงกับตัวที่ต้องการ
                                break;
                            state++; // เปลี่ยนไปเช็คตัวถัดไปของ s
                        }
                    }
                }
            }
        }
    }
    return 0;
}
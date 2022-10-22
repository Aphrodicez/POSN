#include <stdio.h>
#include <string.h>
 
char dir[] = "NESW"; // วนตามเข็มนาฬิกา

/*
การประกาศ array[] โดยไม่กำหนดขนาด จะเป็นการประกาศ array ที่มีขนาดเท่ากับจำนวน element ที่กำหนดไว้
ซึ่ง dir จะมีขนาดเท่ากับ 5 ตัวอักษร คือ N E S W และ \0(null)
แต่เมื่อ printf("%s", dir); จะได้ผลลัพธ์เป็น NESW เพราะ จะปริ้นอักขระตั้งแต่ตัวแรกถึงตัวสุดท้าย ไม่รวม \0
รวมถึงเมื่อใช้ strlen(dir) จะได้ค่าเท่ากับ 4 เพราะไม่นับ \0
*/

char s[110];

int main() {
    scanf(" %s", s + 1); // เก็บ string ไว้ในช่อง s[1] ถึง s[len]
    int len = strlen(s + 1); // นับจำนวนตัวอักษรตั้งแต่ s[1] ก่อนถึง '\0'
    int now_dir = 0; // North
    int i;
    for(i = 1; i <= len; i++) {
        if(s[i] == 'Z') {
            printf("Z");
            now_dir = 0;
            continue;
        }
        while(dir[now_dir] != s[i]) {
            printf("R");
            now_dir = (now_dir + 1) % 4;
            // West -> East [ หมุนขวา 2 รอบ ]
            // การ %
            // 0 1 2 3 4 5 6 7 8 9 10 11
            // 0 1 2 3 0 1 2 3 0 1  2  3
        }
        printf("F");
    }
    return 0;
}

/*
NNEESWZEE

NNEESW

NWSSSSE
*/
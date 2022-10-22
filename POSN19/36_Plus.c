#include <stdio.h>
#include <string.h>

char a[5010]; // 10 ^ 5000
char b[5010]; // 10 ^ 5000
char ans[5010]; // 2 x 10 ^ 5000

int is_a_smaller(char *a, char *b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    if(lena < lenb)
        return 1; // a < b
    if(lena > lenb)
        return 0; // a > b
    int i;
    for(i = 0; i < lena; i++) {
        if(a[i] < b[i])
            return 1; // a < b
        if(a[i] > b[i])
            return 0; // a > b
    }
    return 0; // a == b
}

void plus(char *a, char *b, int sign) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int lenans = 0; // ความยาวของผลลัพธ์
    int i, j;
    int tod = 0;
    // วนย้อนกลับเพื่อบวกทีละหลัก
    for(i = lena - 1, j = lenb - 1; i >= 0 && j >= 0; i--, j--) {
        int val = (a[i] - '0') + (b[j] - '0') + tod; // ผลบวกที่ตำแหน่งนี้ + ทด
        ans[lenans] = val % 10 + '0'; // แปลงผลบวกตำแหน่งนี้เป็น char
        tod = val / 10; // ทด คือ ผลบวกที่ตำแหน่งนี้ / 10 (ปัดลง)
        lenans++; // เพิ่มความยาวของคำตอบ
    }
    // ถ้า a ยังไม่หมด
    for(; i >= 0; i--) {
        int val = (a[i] - '0') + tod;
        ans[lenans] = val % 10 + '0';
        tod = val / 10;
        lenans++;
    }
    // ถ้า b ยังไม่หมด
    for(; j >= 0; j--) {
        int val = (b[j] - '0') + tod;
        ans[lenans] = val % 10 + '0';
        tod = val / 10;
        lenans++;
    }
    // ถ้า tod ยังไม่เท่ากับ 0
    if(tod) {
        ans[lenans] = tod + '0';
        lenans++;
    }
    
    // ช่องสุดท้าย คือ ans[lenans - 1]
    // วนจนกว่าจะเจอตัวแรกที่ไม่ใช่ 0
    for(i = lenans - 1; i >= 0 && ans[i] == '0'; i--);

    if(i == -1) {
        // คำตอบอาจเป็น 0
        printf("0");
        return ;
    }
    if(sign == -1) {
        // ถ้าเป็นลบ
        printf("-");
    }
    // print ย้อนกลับ
    for(; i >= 0; i--)
        printf("%c", ans[i]);
}

void minus(char *more, char *less, int sign) {
    int lenmore = strlen(more);
    int lenless = strlen(less);
    int lenans = 0;
    int i, j;
    for(i = lenmore - 1, j = lenless - 1; i >= 0 && j >= 0; i--, j--) {
        int val = (more[i] - '0') - (less[j] - '0');
        if(val < 0) { // ยืมตัวหน้า
            more[i - 1]--;
            val += 10;
            // ถ้า more[i - 1] เป็น char(0) ซึ่งมีค่า ascii คือ 48 
            // จะกลายเป็น char(') ซึ่งมีค่า ascii คือ 47
            // ซึ่งไม่มีผลต่อการลบเลข
        }
        ans[lenans] = val + '0';
        lenans++;
    }
    // ถ้า more ยังไม่หมด
    for(; i >= 0; i--) {
        int val = (more[i] - '0');
        ans[lenans] = val + '0';
        lenans++;
    }
    // ถ้า less ยังไม่หมด
    for(; j >= 0; j--) {
        int val = (less[j] - '0');
        ans[lenans] = val + '0';
        lenans++;
    }
    // ช่องสุดท้าย คือ ans[lenans - 1]
    // วนจนกว่าจะเจอตัวแรกที่ไม่ใช่ 0
    for(i = lenans - 1; i >= 0 && ans[i] == '0'; i--);

    if(i == -1) {
        // คำตอบเป็นเลข 0
        printf("0");
        return ;
    }
    if(sign == -1) {
        // ถ้าเป็นลบ
        printf("-");
    }
    // print ย้อนกลับ
    for(; i >= 0; i--)
        printf("%c", ans[i]);
}

int main() {
    scanf(" %s", a);
    scanf(" %s", b);
    if(a[0] == '-' && b[0] == '-') {
        strcpy(a, a + 1); // copy ตั้งแต่ตัวที่ 1 ไปจนถึงตัวสุดท้าย มาเก็บไว้ที่ a (เอา - ออก)
        strcpy(b, b + 1); // copy ตั้งแต่ตัวที่ 1 ไปจนถึงตัวสุดท้าย มาเก็บไว้ที่ b (เอา - ออก)
        plus(a, b, -1);
    }
    else if(a[0] == '-') {
        strcpy(a, a + 1);
        if(is_a_smaller(a, b)) // a < b
            minus(b, a, 0);
        else { // a > b
            minus(a, b, -1);
        }
    }
    else if(b[0] == '-') {
        strcpy(b, b + 1);
        if(is_a_smaller(a, b)) {// a < b
            minus(b, a, -1);
        }
        else // a > b
            minus(a, b, 0);
    }
    else {
        plus(a, b, 0);
    }
    return 0;
}
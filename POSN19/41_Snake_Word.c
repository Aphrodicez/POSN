#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};

char a[30][30];
char s[110];
int mark[30][30];

int ansi[110], ansj[110];

int ch;
int len;

int r, c;

void play(int i, int j, int state) {
    if(ch) // ถ้าเจอแล้ว ไม่ต้องค้นหาต่อ
        return ;
    ansi[state] = i;
    ansj[state] = j;
    int k;
    if(state == len - 1) { 
        for(k = 0; k < len; k++)
            printf("%d %d\n", ansi[k], ansj[k]);
        ch = 1; // ติ้กว่าเจอแล้ว
        return;
    }
    for(k = 0; k < 4; k++) {
        int ii = i + d4i[k]; // i ของตำแหน่งที่จะไป
        int jj = j + d4j[k]; // j ของตำแหน่งที่จะไป
        if(ii < 1 || jj < 1 || ii > r || jj > c) // เช็คขอบก่อนทุกเงื่อนไข
            continue;
        if(mark[ii][jj]) // ตำแหน่งนี้เคยไปแล้ว
            continue;
        if(tolower(a[ii][jj]) != tolower(s[state + 1])) // ตัวอักษรไม่ตรงกัน
            continue;
        mark[ii][jj] = 1;
        play(ii, jj, state + 1);
        mark[ii][jj] = 0;
    }
}

int main() {
    scanf("%d %d", &r, &c);
    int i, j;
    for(i = 1; i <= r; i++)
        scanf(" %s", a[i] + 1);
    
    int q;
    scanf("%d", &q);
    while(q--) {
        ch = 0;
        scanf(" %s", s);
        len = strlen(s);
        for(i = 1; i <= r && !ch; i++) {
            for(j = 1; j <= c && !ch; j++) {
                if(tolower(a[i][j]) == tolower(s[0])) {
                    mark[i][j] = 1; // mark ก่อนไป
                    play(i, j, 0);
                    mark[i][j] = 0; // backtrack ลบ mark ออก
                }
            }
        }
        if(!ch)
            printf("No Matching Word\n");   
    }
    return 0;
}

/*
3 5
TAEPE
TULAR
STOPW
2
PEATT
HELLOWORLD
*/
#include <stdio.h>
#include <string.h> // memset()

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};

int a[30][30];

int eni, enj;

int cnt = 0; // มาเหยียบช่องนี้เป็นช่องที่เท่าไหร่
int ch = 0; // ถึงจุดหมายหรือยัง

int r, c, A;

void play(int i, int j) {
    if(ch) // ถ้าเจอแล้ว ไม่ต้องค้นหาต่อ
        return ;
    cnt++;
    a[i][j] = cnt;
    if(i == eni && j == enj) { // Base Case ถึงจุดหมาย
        ch = 1;
        return ;
    }
    int k;
    for(k = A; k < A + 4; k++) { // เริ่มต้นหันหน้าไปทางทิศเหนือ หันตามเข็มนาฬิกาได้ 4 รอบ
        // k มีโอกาสมากกว่า 4 จึงต้อง mod ด้วย 4
        int ii = i + d4i[k % 4]; // i ของตำแหน่งที่จะไป
        int jj = j + d4j[k % 4]; // j ของตำแหน่งที่จะไป
        if(ii < 1 || jj < 1 || ii > r || jj > c) // เช็คขอบก่อนทุกเงื่อนไข
            continue;
        if(a[ii][jj]) // ตำแหน่งนี้เคยไปแล้ว
            continue;
        play(ii, jj);
    }
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        ch = 0;
        cnt = 0;
        memset(a, 0, sizeof(a)); // ล้างตารางให้เป็น 0
        int sti, stj;
        scanf("%d %d %d %d %d %d %d", &r, &c, &A, &sti, &stj, &eni, &enj);
        play(sti, stj);
        int i, j;
        for(i = 1; i <= r; i++) {
            for(j = 1; j <= c; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}

/*
1
5 6 1 3 4 1 4
*/
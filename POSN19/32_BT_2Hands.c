#include <stdio.h>
#include <string.h>

char L[510], R[510]; // string มือซ้าย และ มือขวา
char tmpL[510], tmpR[510]; // string เก่า มือซ้าย และ มือขวา

int main() {
    int o;
    scanf("%d", &o);
    while(o--) {
        char opr;
        scanf(" %c", &opr);
        if(opr == 'q') {
            if(L[0] == '\0') // ถ้ามือซ้ายว่าง [ L[0] == '\0' คือ L ว่าง ]
                printf("- ");
            else
                printf("%s ", L);
            if(R[0] == '\0') // ถ้ามือขวาว่าง [ R[0] == '\0' คือ R ว่าง ]
                printf("-\n");
            else
                printf("%s\n", R);
        }
        else if(opr == 'p') {
            char hand;
            scanf(" %c", &hand);
            if(hand == 'L')
                scanf(" %s", L);
            else
                scanf(" %s", R);
        }
        else if(opr == 'b') {
            strcpy(tmpL, L); // ทำการ copy string มือซ้ายไปยัง tmpL
            strcpy(tmpR, R); // ทำการ copy string มือขวาไปยัง tmpR
            char hand;
            int i;
            scanf(" %c %d", &hand, &i);
            if(hand == 'L')
                L[i] = '\0'; // ตัด string ที่มือซ้ายตั้งแต่ตำแหน่งที่ i ไปจนถึงตัวสุดท้าย
            else
                R[i] = '\0'; // ตัด string ที่มือขวาตั้งแต่ตำแหน่งที่ i ไปจนถึงตัวสุดท้าย
        }
        else if(opr == 'r') {
            strcpy(L, tmpL); // ทำการ copy string tmpL ไปยัง L
            strcpy(R, tmpR); // ทำการ copy string tmpR ไปยัง R
        }
        else if(opr == 'c') {
            char hand;
            scanf(" %c", &hand);
            if(hand == 'L') {
                strcat(L, R); // นำ string R มาต่อท้าย string L
                R[0] = '\0'; // ทำให้ string R ว่าง
            }
            else {
                strcat(R, L); // นำ string L มาต่อท้าย string R
                L[0] = '\0'; // ทำให้ string L ว่าง
            }
        }
    }
    return 0;
}

/*
14 
q
p L peat
p R teap
q
c L
q
b L 4
q
r
q
b L 4
p R teap
c R
q
*/
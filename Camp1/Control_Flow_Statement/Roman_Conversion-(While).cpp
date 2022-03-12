#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int m;
        scanf("%d", &m);
        while(m >= 1000)
            printf("M"), m -= 1000;
        while(m >= 900)
            printf("CM"), m -= 900;
        while(m >= 500)
            printf("D"), m -= 500;
        while(m >= 400)
            printf("CD"), m -= 400;
        while(m >= 100)
            printf("C"), m -= 100;
        while(m >= 90)
            printf("XC"), m -= 90;
        while(m >= 50)
            printf("L"), m -= 50;
        while(m >= 40)
            printf("XL"), m -= 40;
        while(m >= 10)
            printf("X"), m -= 10;
        while(m >= 9)
            printf("IX"), m -= 9;
        while(m >= 5)
            printf("V"), m -= 5;
        while(m >= 4)
            printf("IV"), m -= 4;
        while(m >= 1)
            printf("I"), m -= 1;
        printf("\n");
    }
    return 0;
}

/*
3
726
49
2489
*/
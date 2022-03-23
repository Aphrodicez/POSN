#include <stdio.h>
#include <string.h>
#include <ctype.h>

char a[40], b[40];
char ans[40];

int toBase10(char* s, int base) {
    int len = strlen(s);
    int num = 0;
    for(int i = 0; i < len; i++) {
        num *= base;
        if(isdigit(s[i]))
            num += s[i] - '0';
        else if(isalpha(s[i]))
            num += s[i] - 'A' + 10;
    }
    return num;
}

int main() {
    int base;
    scanf("%d", &base);
    scanf(" %s", a);
    scanf(" %s", b);
    int numA = toBase10(a, base);
    int numB = toBase10(b, base);
    int sum = numA + numB;
    printf("%d\n", sum);
    int sz = 0;
    for( ; sum > 0; ) {
        int val = sum % base;
        char now;
        if(val >= 10)
            now = val - 10 + 'A';
        else
            now = val + '0';
        ans[sz++] = now;
        sum /= base;
    }
    for(int i = sz - 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    return 0;
}

/*
16
12A
321
*/

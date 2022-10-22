#include <stdio.h>
#include <string.h>

char s[30];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf(" %s", s);
        int len = strlen(s);
        int ans = 0; // อย่าลืมล้างค่าตัวแปรทุกคำถาม
        int i;
        for(i = 0; i < len; ) {
            if(s[i] == 'M') {
                ans += 1000;
                i++;
            }
            else if(i + 1 < len && s[i] == 'C' && s[i + 1] == 'M') {
                // การเช็คขอบ array ควรทำเป็นเงื่อนไขแรกของ if
                ans += 900;
                i += 2;
            }
            else if(s[i] == 'D') {
                ans += 500;
                i++;
            }
            else if(i + 1 < len && s[i] == 'C' && s[i + 1] == 'D') {
                ans += 400;
                i += 2;
            }
            else if(s[i] == 'C') {
                ans += 100;
                i++;
            }
            else if(i + 1 < len && s[i] == 'X' && s[i + 1] == 'C') {
                ans += 90;
                i += 2;
            }
            else if(s[i] == 'L') {
                ans += 50;
                i++;
            }
            else if(i + 1 < len && s[i] == 'X' && s[i + 1] == 'L') {
                ans += 40;
                i += 2;
            }
            else if(s[i] == 'X') {
                ans += 10;
                i++;
            }
            else if(i + 1 < len && s[i] == 'I' && s[i + 1] == 'X') {
                ans += 9;
                i += 2;
            }
            else if(s[i] == 'V') {
                ans += 5;
                i++;
            }
            else if(i + 1 < len && s[i] == 'I' && s[i + 1] == 'V') {
                ans += 4;
                i += 2;
            }
            else if(s[i] == 'I') {
                ans += 1;
                i++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
DCCXXVI
XLIX
MMCDLXXXIX
*/

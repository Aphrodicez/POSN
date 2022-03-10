#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    scanf(" %c", &c);
    int base = 'A';
    if(islower(c))
        base = 'a';
    int ans = (c - base + 2) % 26 + base;
    printf("%c\n", ans);
    return 0;
}
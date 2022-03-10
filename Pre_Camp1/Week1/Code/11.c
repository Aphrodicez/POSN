#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    scanf("%c", &c);
    if(isupper(c))
        printf("%c\n", tolower(c));
    else
        printf("%c\n", toupper(c));
    return 0;
}
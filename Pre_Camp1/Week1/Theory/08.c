#include <stdio.h>

int main() {
    char x;
    scanf("%c", &x);
    if(x >= 'A' && x <= 'Z')
        printf("Big\n");
    else if(x >= 'a' && x <= 'z')
        printf("Small\n");
    else
        printf("Not Alphabet\n");
    return 0;
}
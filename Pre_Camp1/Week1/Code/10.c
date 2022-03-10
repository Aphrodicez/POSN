#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    scanf("%c", &c);
    if(isupper(c))
        printf("Big\n");
    else if(islower(c))
        printf("Small\n");
    else
        printf("Not Alphabet\n");
    return 0;
}
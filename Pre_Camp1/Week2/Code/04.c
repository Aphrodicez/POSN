#include <stdio.h>

char a[3][10];

int main() {
    for(int i = 0; i < 3; i++)
        scanf(" %s", a[i]);
    for(int i = 2; i >= 0; i--)
        printf("%s\n", a[i]);
    return 0;
}

/*
Fern
Mew
Kersa
*/
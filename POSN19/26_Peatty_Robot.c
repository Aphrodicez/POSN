#include <stdio.h>
#include <string.h> // strlen()

char s[110];

int main() {
    scanf(" %s", s);
    int len = strlen(s);
    int x = 0, y = 0;
    int i;
    for(i = 0; i < len; i++) {
        if(s[i] == 'Z')
            x = 0, y = 0;
        else if(s[i] == 'N')
            y++;
        else if(s[i] == 'E')
            x++;
        else if(s[i] == 'S')
            y--;
        else if(s[i] == 'W')
            x--;
    }
    printf("%d %d", x, y);
    return 0;
}

/*
NNEESWZEE

NNEESW

NWSSSSE
*/
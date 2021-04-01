#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    scanf(" %c", &c);
    if(isupper(c)){
        c = tolower(c);
    }
    else if(islower(c)){
        c = toupper(c);
    }
    printf("%c", c);
    return 0;
}
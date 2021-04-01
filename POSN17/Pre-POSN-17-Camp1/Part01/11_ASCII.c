#include <stdio.h>

int main(){
    char c;
    scanf(" %c", &c);
    if(c >= 65 && c <= 90){
        c += 32;
    }
    else if(c >= 'a' && c <= 'z'){
        c -= 32;
    }
    printf("%c", c);
    return 0;
}
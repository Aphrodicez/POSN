#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    scanf(" %c", &c);
    if(isupper(c)){
        printf("Big");
    }
    else if(islower(c)){
        printf("Small");
    }
    else{
        printf("Not Alphabet");
    }
    return 0;
}
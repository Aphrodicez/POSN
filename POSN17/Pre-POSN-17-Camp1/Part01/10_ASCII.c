#include <stdio.h>

int main(){
    char c;
    scanf(" %c", &c);
    if(c >= 'A' && c <= 'Z'){
        printf("Big");
    }
    else if(c >= 97 && c <= 122){
        printf("Small");
    }
    else{
        printf("Not Alphabet");
    }
    return 0;
}
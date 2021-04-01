#include <stdio.h>

char s[10][110];

int main(){
    for(int i = 0; i < 3; i++){
        scanf(" %s", s[i]);
    }
    for(int i = 2; i >= 0; i--){
        printf("%s\n", s[i]);
    }
    return 0;
}
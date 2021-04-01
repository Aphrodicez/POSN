#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n > 0){
        printf("Positive Integer");
    }
    else if(n < 0){
        printf("Negative Integer");
    }
    else{
        printf("Zero Integer");
    }
    return 0;
}
#include <stdio.h>

int a[1100];

int main(){
    int n, ch = 0; /// ch = check
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 0)
            ch = 1;
    }
    if(ch == 1){
        printf("Have");
    }
    else{
        printf("Don't have");
    }
    return 0;
}
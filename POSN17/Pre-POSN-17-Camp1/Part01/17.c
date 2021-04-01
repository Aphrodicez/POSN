#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n % 2 == 1)
        n--;
    for(int i = n; i >= 2; i-=2){
        printf("%d\n", i);
    }
    return 0;
}
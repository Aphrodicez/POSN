#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int i;
    for(i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    i = n;
    while(i > 0) {
        printf("%d ", i--);
    }
    printf("\n");
    
    if(n >= 2) {
        i = 2;
        do {
            printf("%d ", i);
            i += 2;
        }while(i <= n);
    }
    printf("\n");
    
    i = n / 2 * 2;
    for(; i >= 2; i -= 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    i = 1;
    while(i <= n) {
        printf("%d ", i);
        i += 2;
    }
    printf("\n");

    i = n - (n % 2 == 0);
    do {
        printf("%d ", i);
        i -= 2;
    }while(i >= 1);
    printf("\n");
    return 0;
}

/*
15
*/
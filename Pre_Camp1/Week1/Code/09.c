#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n > 0)
        printf("Positive Integer\n");
    else if(n < 0)
        printf("Negative Integer\n");
    else
        printf("Zero Integer\n");
    return 0;
}

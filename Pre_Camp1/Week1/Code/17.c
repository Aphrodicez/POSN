#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = n - (n % 2); i > 0; i -= 2)
        printf("%d\n", i);
    return 0;
}
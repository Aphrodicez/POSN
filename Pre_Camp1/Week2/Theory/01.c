#include <stdio.h>

int main() {
    int n, i, a[1000];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}
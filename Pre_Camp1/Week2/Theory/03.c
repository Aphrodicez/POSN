#include <stdio.h>

int main() {
    int n, i, a[1000], max = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++)
        if(a[i] > max)
            max = a[i];
    printf("%d\n", max);
    return 0;
}
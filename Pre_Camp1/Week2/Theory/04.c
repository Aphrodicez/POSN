#include <stdio.h>

int main() {
    int n, i, a[1000], count;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0, count = 0; i < n; i++)
        if(a[i] == 5)
            count++;
    printf("%d\n", count);
    return 0;
}
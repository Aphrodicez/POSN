#include <stdio.h>

int main() {
    int n, i;
    double a[1000];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%lf", &a[i]);
    for(i = n - 1; i >= 0; i--)
        printf("%.2lf\n", a[i]);
    return 0;
}
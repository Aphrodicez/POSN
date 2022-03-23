#include <stdio.h>

int gcd(int a, int b) {
    if(!a || !b)
        return a + b;
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        ans = ans / gcd(ans, val) * val;
    }
    printf("%d\n", ans);
    return 0;
}

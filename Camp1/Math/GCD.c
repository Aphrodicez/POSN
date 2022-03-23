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
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        ans = gcd(ans, val);
    }
    printf("%d\n", ans);
    return 0;
}

/*
2
192
270

4
16
24
12
32
*/

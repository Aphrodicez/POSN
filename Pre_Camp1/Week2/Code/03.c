#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int mn = 2e9, mx = -2e9;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if(mn > val)
            mn = val;
        if(mx < val)
            mx = val;
    }
    printf("%d\n%d\n", mn, mx);
    return 0;
}
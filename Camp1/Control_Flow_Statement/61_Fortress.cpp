#include <stdio.h>

int main() {
    int q = 20;
    while(q--) {
        int m, n;
        scanf("%d %d", &m, &n);
        int mid = (m - 2 * n) / 2;
        if(mid < 0 || mid > n)
            printf("0\n");
        else
            printf("%d\n", (m - 4 * mid) / 2 + 1);
    }
    return 0;
}

/*
40 15
30 12
60 40
50 18
66 26
36 11
36 16
36 18
56 20
56 22
44 18
32 14
42 20
36 16
38 14
38 16
34 20
36 16
44 14
34 14
*/
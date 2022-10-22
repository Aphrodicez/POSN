#include <stdio.h>
#include <string.h>

char s[1010];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf(" %s", s);
        int len = strlen(s);
        int n, k;
        scanf("%d %d", &n, &k);
        k %= n;
        int i;
        for(i = 0; i < len; i++) {
            int st = i - (i % n); // ช่องแรกของ interval ที่ i อยู่
            int idx = i % n; // ตำแหน่งของ i ใน interval
            int new_idx = (idx - k + n) % n; // ตำแหน่งของตัวที่จะมาแทนที่ idx ใน interval
            printf("%c", s[st + new_idx]); // ตัวที่จะมาแทนที่ s[i]
        }
        printf("\n");
    }
    return 0;
}
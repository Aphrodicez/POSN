#include <stdio.h>

int a[110];

int scores[20 + 10];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int i;
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int p = 1; // players = 1 -> k
    int now = 0; // position = 1 -> n
    for(i = 1; i <= n; i++) { // Roll the dice n round
        int x;
        scanf("%d", &x);
        x++; // ข้าม x ครั้ง = เดิน (x + 1) ครั้ง
        while(x--) { // เดิน (x + 1) ครั้ง
            now = (now % n) + 1; // if (now == n) now = 1; else now++;
            while(a[now] == 0)
                now = (now % n) + 1; // เดินจนกว่าจะเจอตำแหน่งที่ยังไม่ถูกเลือก
        }
        scores[p] += a[now];
        a[now] = 0;
        p = (p % k) + 1; // if (p == k) p = 1; else p++;
    }
    for(i = 1; i <= k; i++)
        printf("%d\n", scores[i]);
    return 0;
}
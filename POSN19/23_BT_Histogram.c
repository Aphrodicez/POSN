#include <stdio.h>

int cnt[1010]; // Counting array

int main() {
    int n;
    scanf("%d", &n);
    int MaxH = 0, MaxW = 0; // Max height and Max width
    int i, j;
    for(i = 0; i < n; i++) {
        int x; // Position in the x-axis
        scanf("%d", &x);
        if(MaxW < x) // Find the maximum width
            MaxW = x;
        
        cnt[x]++; // Count the number of points in each position
        if(MaxH < cnt[x]) // Find the maximum height
            MaxH = cnt[x];
    }
    for(i = 1; i <= MaxH; i++) {
        for(j = 1; j <= MaxW; j++) {
            if(i > MaxH - cnt[j]) // MaxH - cnt[j] = แถวสุดท้ายที่ไม่ใช่ '*' ในแต่ละคอลัมน์
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
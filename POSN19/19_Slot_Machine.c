#include <stdio.h> 

int a[15 + 10][5 + 10]; // MaxN = 15

int ans[759375 + 10][5 + 10]; // 5 ^ 5

int main() {
    int n;
    scanf("%d", &n);
    int i, j, k, l, m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= 5; j++)
            scanf("%d", &a[i][j]);
    
    int cnt = 0;

    for(i = 1; i <= n; i++) // Column 1
        for(j = 1; j <= n; j++) // Column 2
            for(k = 1; k <= n; k++) // Column 3
                for(l = 1; l <= n; l++) // Column 4
                    for(m = 1; m <= n; m++) // Column 5
                        if(a[i][1] == a[j][2] && a[j][2] == a[k][3] && a[k][3] == a[l][4] && a[l][4] == a[m][5]) {
                            ++cnt; // เพิ่มจำนวนชุดคำตอบที่เจอ
                            ans[cnt][1] = i, ans[cnt][2] = j, ans[cnt][3] = k, ans[cnt][4] = l, ans[cnt][5] = m;
                        }
    
    printf("%d\n", cnt);
    for(i = 1; i <= cnt; i++) {
        for(j = 1; j <= 5; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}
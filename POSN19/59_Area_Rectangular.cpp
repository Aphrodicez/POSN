#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e3 + 10;

int a[MaxN][MaxN];
int dp[MaxN][MaxN];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            // เริ่มที่ i = 1, j = 1 เพื่อให้สามารถเรียก dp[i - 1][j - 1] ได้
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int sti, stj, eni, enj; // st = UpLeft, en = DownRight
        scanf("%d %d %d %d", &sti, &stj, &eni, &enj);
        sti++, stj++, eni++, enj++;
        printf("%d\n", dp[eni][enj] - dp[sti - 1][enj] - dp[eni][stj - 1] + dp[sti - 1][stj - 1]);
    }
    return 0;
}

/*
3 4
3 7 -2 12
0 -4 9 -3
6 3 8 -1
2
0 1 1 3
0 0 2 2
*/
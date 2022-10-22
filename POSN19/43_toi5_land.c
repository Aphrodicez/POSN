#include <stdio.h>

const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

double a[5][5]; // 3 x 3
int mark[5][5];

double ans = 2e9;

int r, c;

void play(int state, double sum) {
    if(ans < sum) // ไม่มีทางที่ sum จะน้อยกว่า ans ได้
        return ;
    if(state == r * c) { // Base Case ซื้อครบทุกช่องแล้ว
        if(ans > sum)
            ans = sum;
        return;
    }
    int i, j;
    for(i = 1; i <= r; i++) {
        for(j = 1; j <= c; j++) {
            if(mark[i][j])
                continue;
            int k;

            mark[i][j] = 1;
            for(k = 0; k < 8; k++) {
                int ii = i + d8i[k];
                int jj = j + d8j[k];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    continue;
                a[ii][jj] += 0.1 * a[i][j]; // เพิ่มราคาเมืองที่ติดกัน
            }
            play(state + 1, sum + a[i][j]);

            mark[i][j] = 0;
            for(k = 0; k < 8; k++) {
                int ii = i + d8i[k];
                int jj = j + d8j[k];
                if(ii < 1 || jj < 1 || ii > r || jj > c)
                    continue;
                a[ii][jj] -= 0.1 * a[i][j]; // ลดราคาเมืองที่ติดกันให้เหมือนเดิม
            }
        }
    }
}

int main() {
    scanf("%d %d", &r, &c);
    int i, j;
    for(i = 1; i <= r; i++)
        for(j = 1; j <= c; j++)
            scanf("%lf", &a[i][j]);
    play(0, 0);
    printf("%.2lf", ans);
    return 0;
}
#include <stdio.h>
#include <string.h>

int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

int r, c;

char a[1100][100];

int cnt = 0;

void play(int i, int j) {
    for(int k = 0; k < 8; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];
        if(ii < 1 || jj < 1 || ii > r || jj > c)
            continue;
        if(a[ii][jj] != '*')
            continue;
        cnt++;
        a[ii][jj] = '.';
        play(ii, jj);
    }
}

int main() {
    scanf("%d %d", &c, &r);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
    }
    int ans = r * c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(a[i][j] == '*') {
                cnt = 0;
                cnt++;
                a[i][j] = '.';
                play(i, j);
                if(ans > cnt)
                    ans = cnt;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

/*
10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***
*/

#include <stdio.h>

char a[30][30];
int col[30], cnt[30];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int j = 1; j <= c; j++)
        col[j] = r + 1;
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
        for(int j = 1; j <= c; j++)
            if(a[i][j] == 'O' && col[j] > i)
                col[j] = i;
    }
    for(int j = 1; j <= c; j++) {
        scanf("%d", &cnt[j]);
        cnt[j] = col[j] - cnt[j];
        for(int i = 1; i < col[j]; i++)
            if(i >= cnt[j])
                a[i][j] = '#';
    }
    for(int i = 1; i <= r; i++) {
        printf("%s\n", a[i] + 1);
    }
    return 0;
}

/*
8 5
.....
.....
.OO..
.....
.O...
...O.
.....
.....
1 1 3 2 0
*/
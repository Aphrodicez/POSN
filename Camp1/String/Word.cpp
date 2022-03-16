#include <stdio.h>
#include <string.h>
#include <ctype.h>

int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};

char a[40][40];
char s[30];

int ch = 0;

int r, c;
int len;

void dfs(int i, int j, int state, int k) {
    if(ch)
        return;
    if(state == len - 1) {
        ch = 1;
        return ;
    }
    int ii = i + di[k];
    int jj = j + dj[k];
    if(ii < 0 || jj < 0 || ii > r - 1 || jj > c - 1)
        return ;
    if(a[ii][jj] != s[state + 1])
        return ;
    dfs(ii, jj, state + 1, k);
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        scanf(" %s", a[i]);
        for(int j = 0; j < c; j++) {
            a[i][j] = toupper(a[i][j]);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        ch = 0;
        scanf(" %s", s);
        len = strlen(s);
        for(int i = 0; i < len; i++) {
            s[i] = toupper(s[i]);
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(a[i][j] == s[0]) {
                    for(int k = 0; k < 8; k++) {
                        dfs(i, j, 0, k);
                        if(ch) {
                            printf("%d %d\n", i, j);
                            break;
                        }
                    }
                }
                if(ch)
                    break;
            }
            if(ch)
                break;
        }
    }
    return 0;
}

/*
8 11
ascDEFGhigg
hTqkComPutk
FayUcompuTm
FcsierMqsrc
bkoArUePeyv
Klcbqwekumk
sreTNIophtb
yUiqlxcnBje
4
Compute
Queue
stack
Pointer
*/
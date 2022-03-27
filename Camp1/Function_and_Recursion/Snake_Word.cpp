/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Recursion + Backtracking
    Status	: Accepted
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

char a[30][30];
char s[110];
int mark[30][30];

int ansi[110], ansj[110];

int ch = 0;

int r, c;
int len;

void play(int i, int j, int state) {
    if(ch)
        return ;
    ansi[state] = i, ansj[state] = j;
    if(state == len) {
        ch = 1;
        for(int k = 1; k <= len; k++) {
            printf("%d %d\n", ansi[k], ansj[k]);
        }
        return ;
    }
    for(int k = 0; k < 4; k++) {
        int ii = i + di[k];
        int jj = j + dj[k];
        if(ii < 1 || jj < 1 || ii > r || jj > c)
            continue;
        if(a[ii][jj] != s[state + 1])
            continue;
        if(mark[ii][jj])
            continue;        
        mark[ii][jj] = 1;
        play(ii, jj, state + 1);
        mark[ii][jj] = 0;
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++) {
        scanf(" %s", a[i] + 1);
        for(int j = 1; j <= c; j++) {
            a[i][j] = tolower(a[i][j]);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        ch = 0;
        scanf(" %s", s + 1);
        len = strlen(s + 1);
        for(int i = 1; i <= len; i++) {
            s[i] = tolower(s[i]);
        }
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(a[i][j] == s[1]) {
                    mark[i][j] = 1;
                    play(i, j, 1);
                    mark[i][j] = 0;
                }
                if(ch)
                    break;
            }
            if(ch)
                break;
        }
        if(!ch)
            printf("No Matching Word\n");
    }
    return 0;
}

/*
3 5
TAEPE
TULAR
STOPW
3
PEATT
PEATA
HELLOWORLD
*/
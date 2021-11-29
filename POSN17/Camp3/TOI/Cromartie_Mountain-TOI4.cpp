/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Array
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 2e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char a[20][110];
int l[MaxN], h[MaxN];
bitset <110> markv;

void drawhill(int i, int j, int h, int dir, char tmp) {
    if(!h)
        return ;
    bool chv = false;
    chv |= (tmp == '/' && a[i][j] == '\\');
    chv |= (a[i][j] == '/' && tmp == '\\');
    if(chv)
        a[i][j] = 'v';
    else
        a[i][j] = tmp;
    drawhill(i - 1, j + dir, h - 1, dir, tmp);
}

void solve() {
    memset(a, '.', sizeof (a));
    int n;
    scanf("%d", &n);
    int row = 0, col = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &h[i]);
        row = max(row, h[i]);
        col = max(col, l[i] + 2 * h[i] - 1);
    }
    for(int i = 1; i <= n; i++) {
        drawhill(row, l[i], h[i], 1, '/');
        drawhill(row, l[i] + 2 * h[i] - 1, h[i], -1, '\\');
    }
    for(int i =  1; i <= row; i++) {
        int sum = 0;
        for(int j = 1; j <= col; j++) {
            if(a[i][j] == 'v' && !markv[j]) {
                markv[j] = true;
                continue;
            }
            char tmp = a[i][j];
            sum -= (tmp == '\\');
            if(sum)
                a[i][j] = 'X';
            sum += (tmp == '/');
        }
    }
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
3
5 6
2 4
16 3

5
1 4
6 7
12 6
21 5
41 3
*/
#include <stdio.h>
#include <string.h>

char a[500][500];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        memset(a, '.', sizeof (a));
        int n;
        scanf("%d", &n);
        n = 4 * n - 3;
        int i = 1, j = 1;
        a[i][j] = '#';
        while(1) {
            int ch = 0;
            while(j + 1 <= n && a[i][j + 2] != '#') {
                ch = 1;
                j++;
                a[i][j] = '#';
            }
            while(i + 1 <= n && a[i + 2][j] != '#') {
                i++;
                a[i][j] = '#';
            }
            while(j - 1 >= 1 && a[i][j - 2] != '#') {
                j--;
                a[i][j] = '#';
            }
            while(i - 1 >= 1 && a[i - 2][j] != '#') {
                i--;
                a[i][j] = '#';
            }
            if(!ch)
                break;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                printf("%c", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

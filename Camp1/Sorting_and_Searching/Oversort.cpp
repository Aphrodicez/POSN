#include <bits/stdc++.h>
using namespace std;

struct A {
    char s[110];
    bool operator < (const A& o) const {
        if(strcmp(s, o.s) < 0)
            return true;
        return false;
    }
};

int a[100100];
double b[100100];
char c[100100];
A d[100100];

int main() {
    int opr;
    scanf("%d", &opr);
    int n;
    scanf("%d", &n);
    if(opr == 1) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        sort(a + 1, a + n + 1, greater<int>());
        for(int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    if(opr == 2) {
        for(int i = 1; i <= n; i++) {
            scanf("%lf", &b[i]);
        }
        sort(b + 1, b + n + 1);
        for(int i = 1; i <= n; i++) {
            printf("%.0lf ", b[i]);
        }
        printf("\n");
        sort(b + 1, b + 1 + n, greater<double>());
        for(int i = 1; i <= n; i++) {
            printf("%.0lf ", b[i]);
        }
        printf("\n");
    }
    if(opr == 3) {
        for(int i = 0; i < n; i++) {
            scanf(" %c", &c[i]);
        }
        sort(c, c + n);
        for(int i = 0; i < n; i++) {
            printf("%c ", c[i]);
        }
        printf("\n");
        sort(c, c + n, greater <char>());
        for(int i = 0; i < n; i++) {
            printf("%c ", c[i]);
        }
        printf("\n");
    }
    if(opr == 4) {
        for(int i = 1; i <= n; i++) {
            scanf(" %s", d[i].s);
        }
        sort(d + 1, d + 1 + n);
        for(int i = 1; i <= n; i++) {
            printf("%s ", d[i].s);
        }
        printf("\n");
        for(int i = n; i >= 1; i--) {
            printf("%s ", d[i].s);
        }
        printf("\n");
    }
    return 0;
}

/*
1
4
5 2 5 7

2
3
4.78 3.14 16

3
4
# A f *

4
5
peatt peat e pot handsome
*/

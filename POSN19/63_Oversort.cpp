#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

struct A {
    char s[110];
    bool operator < (const A &o) const {
        if(strcmp(s, o.s) < 0)
            return true; 
        return false; // ถ้า s == o.s ถือว่า false (ไม่น้อยกว่า)
    }
};

int a[MaxN];
double b[MaxN];
char c[MaxN];
A d[MaxN];

int main() {
    int opr;
    scanf("%d", &opr);
    int n;
    scanf("%d", &n);
    if(opr == 1) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, (a + 1) + n);
        for(int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        sort(a + 1, (a + 1) + n, greater<int>()); // เรียงจากมากไปน้อย
        for(int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    else if(opr == 2) {
        for(int i = 1; i <= n; i++) {
            scanf("%lf", &b[i]);
        }
        sort(b + 1, (b + 1) + n);
        for(int i = 1; i <= n; i++) {
            printf("%.0lf ", b[i]);
        }
        printf("\n");
        sort(b + 1, (b + 1) + n, greater<double>()); // เรียงจากมากไปน้อย
        for(int i = 1; i <= n; i++) {
            printf("%.0lf ", b[i]);
        }
        printf("\n");
    }
    else if(opr == 3) {
        for(int i = 1; i <= n; i++) {
            scanf(" %c", &c[i]);
        }
        sort(c + 1, (c + 1) + n);
        for(int i = 1; i <= n; i++) {
            printf("%c ", c[i]);
        }
        printf("\n");
        sort(c + 1, (c + 1) + n, greater<char>()); // เรียงจากมากไปน้อย
        for(int i = 1; i <= n; i++) {
            printf("%c ", c[i]);
        }
        printf("\n");
    }
    else if(opr == 4) {
        for(int i = 1; i <= n; i++) {
            scanf(" %s", d[i].s);
        }
        sort(d + 1, (d + 1) + n);
        for(int i = 1; i <= n; i++) {
            printf("%s ", d[i].s);
        }
        printf("\n");
        // sort(d + 1, (d + 1) + n, greater<A>()); [Error]
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
#include <stdio.h>
#include <string.h>

char a[110];

int main() {
    scanf(" %s", a);
    int len = strlen(a);
    int k;
    scanf("%d", &k);
    int n = 0, s = 0, e = 0, w = 0;
    for(int i = 0; i < len; i++) {
        if(a[i] == 'N')
            n++;
        else if(a[i] == 'S')
            s++;
        else if(a[i] == 'E')
            e++;
        else
            w++;
    }
    int tmp;
    if(n < s) {
        tmp = n;
        n = s;
        s = tmp;
    }
    if(s >= k)
        s -= k, k = 0;
    else
        k -= s, s = 0;
    if(e < w) {
        tmp = e;
        e = w;
        w = tmp;
    }
    if(w >= k)
        w -= k, k = 0;
    else
        k -= w, w = 0;
    printf("%d\n", 2 * (n - s + e - w - k));
    return 0;
}
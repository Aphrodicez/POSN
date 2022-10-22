#include <stdio.h>
#include <string.h>

char a[110];

int main() {
    scanf(" %s", a);
    int len = strlen(a);
    int k;
    scanf("%d", &k);
    int n = 0, e = 0, w = 0, s = 0;
    int i;
    for(i = 0; i < len; i++) {
        if(a[i] == 'N')
            n++;
        else if(a[i] == 'E')
            e++;
        else if(a[i] == 'W')
            w++;
        else if(a[i] == 'S')
            s++;
    }
    int max_pair = 0; // max(n, s)  + max(e, w)
    int min_pair = 0; // min(n, s)  + min(e, w)

    if(n > s)
        max_pair += n, min_pair += s;
    else
        max_pair += s, min_pair += n;

    if(e > w)
        max_pair += e, min_pair += w;
    else
        max_pair += w, min_pair += e;

    int mn = min_pair;
    if(mn > k)
        mn = k;
    // mn = min(min_pair, k);
    // min_pair หรือ k ตัวใดตัวหนึ่งกลายเป็น 0
    min_pair -= mn;
    k -= mn;
    // ถ้าเหลือ k แสดงว่าต้องลด max_pair ด้วย
    printf("%d", 2 * (max_pair - min_pair - k)); // ระยะทางไป-กลับ
    return 0;
}

/*
NNEESW
2

NE
2

NWSSSSE
1
*/
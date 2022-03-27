/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e2 + 10;

char a[MaxN];

int main(){
    scanf(" %s", a);
    int n = 0, e = 0, s = 0, w = 0;
    int k;
    scanf("%d", &k);
    int len = strlen(a);
    for(int i = 0; i < len; i++) {
        n += (a[i] == 'N');
        e += (a[i] == 'E');
        s += (a[i] == 'S');
        w += (a[i] == 'W');
    }
    int diff;
    if(n >= s) {
        diff = min(k, s);
        s -= diff;
        k -= diff;
    }
    else {
        diff = min(k, n);
        n -= diff;
        k -= diff;
    }
    if(e >= w) {
        diff = min(k, w);
        w -= diff;
        k -= diff;
    }
    else {
        diff = min(k, e);
        e -= diff;
        k -= diff;
    }
    int ans = abs(n - s) + abs(e - w) - k;
    printf("%d\n", 2 * ans);
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
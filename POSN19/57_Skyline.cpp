#include <bits/stdc++.h>
using namespace std;

int MaxH[256 + 10];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int l, h, r;
        scanf("%d %d %d", &l, &h, &r);
        for(int i = l; i <= r - 1; i++) {
            MaxH[i] = max(MaxH[i], h);
        }
    }
    for(int i = 1; i <= 256; i++)
        if(MaxH[i] != MaxH[i - 1])
            printf("%d %d ", i, MaxH[i]);
    return 0;
}

/*
8
1 11 5
2 6 7
12 7 6
14 3 25
19 18 22
3 13 9
23 13 29
24 4 28
*/
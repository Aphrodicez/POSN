/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Counting Sort
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> se, ne, mpx, mpy;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        bool ch = false;
        ch |= (++mpx[x] == k);
        ch |= (++mpy[y] == k);
        ch |= (++ne[x - y] == k);
        ch |= (++se[x + y] == k);
        if(ch) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

/*
5 3
1 3
3 5
3 3
4 6
5 7
*/
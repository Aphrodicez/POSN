#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

map <int, int> mp;

int a[MaxN];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            mp[a[i]]++;
        }
        bool ch = false;
        for(int i = 1; i <= n; i++) {
            if(mp[a[i]] == 1) {
                printf("%d ", a[i]);
                ch = true;
            }
        }
        if(!ch)
            printf("No Alone Num");
        printf("\n");
        mp.clear();
    }
    return 0;
}

/*
3
9
3 2 1 2 3 7 3 6 8
7
1 3 2 4 2 0 1
6
-1 -2 -3 -3 -2 -1
*/

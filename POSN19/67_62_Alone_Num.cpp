#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

int a[MaxN];

map <int, int> mp;

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            mp[a[i]]++;
            //mp[key] = value;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(mp[a[i]] == 1) {
                printf("%d ", a[i]);
                cnt++;
            }
        }
        if(!cnt)
            printf("No Alone Num");
        printf("\n");
        mp.clear();
    }
    return 0;
}

/*

*/
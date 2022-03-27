/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e3 + 10;

int a[MaxN];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort((a + 1), (a + 1) + n, greater <int>());
    int ans = 0;
    for(int i = 1; i <= n; i += k)
        ans += a[i];
    printf("%d\n", ans);
    return 0;
}

/*
5 3
6
1
2
8
7
*/
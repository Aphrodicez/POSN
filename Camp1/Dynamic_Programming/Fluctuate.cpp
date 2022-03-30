/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Dynamic Programming
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int a[1000010];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    int mx = 0;
    for(int i = n; i >= 1; i--) {
        mx = max(mx, a[i]);
        ans = max(ans, mx - a[i]);
    }
    printf("%d\n", ans);
    return 0;
}

/*
5
2 3 7 4 6
*/
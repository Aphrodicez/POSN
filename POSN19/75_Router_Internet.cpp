#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

double a[MaxN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%lf", &a[i]);
    
    sort(a + 1, (a + 1) + m);
    
    double l = 0, r = 1e6;
    while(l + 1e-6 < r) {
        double mid = l + (r - l) / 2;
        int cnt = 1;
        double last = a[1] + mid; // Nearest Router
        for(int i = 2; i <= m; i++) {
            if(abs(a[i] - last) > mid) {
                last = a[i] + mid;
                cnt++;
            }
            if(cnt > n)
                break;
        }
        if(cnt > n)
            l = mid + 1e-6;
        else
            r = mid;
        //break;
    }
    printf("%.1lf", l);
    return 0;
}

/*
2 3
1 3 10
*/
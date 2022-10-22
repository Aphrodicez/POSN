#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

long long t[MaxN];

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &t[i]);
    }
    long long l = 1, r = 1e18;
    while(l < r) {
        long long mid = l + (r - l) / 2; // (l + r) / 2
        long long sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += mid / t[i];
            if(sum >= m)
                break;
        }
        if(sum >= m)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld", l);
    return 0;
}

/*
2 6
7
10
*/
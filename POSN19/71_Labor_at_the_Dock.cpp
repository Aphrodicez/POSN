#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 10;

long long t[MaxN];

int main() {
    int m;
    long long n;
    scanf("%d %lld", &m, &n);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &t[i]);
    
    long long l = 1, r = 1e18;
    while(l < r) {
        long long mid = l + (r - l) / 2; // (l + r) / 2
        long long sum = 0;
        for(int i = 1; i <= m; i++) {
            sum += mid / t[i];
            if(sum >= n)
                break;
        }
        if(sum >= n)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld", l);
    return 0;
}

/*
2 5
7
12

3 3
6
13
2

2 2
5
5
*/
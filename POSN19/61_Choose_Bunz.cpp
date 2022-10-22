#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e4 + 10;

int nCr[2][MaxN]; // Optimized Space

int main() {
    int n, r, k;
    scanf("%d %d %d", &n, &r, &k);
    nCr[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        nCr[i % 2][0] = 1;
        for(int j = 1; j <= i; j++) {
            nCr[i % 2][j] = nCr[1 - i % 2][j - 1] + nCr[1 - i % 2][j];
            nCr[i % 2][j] %= k;
        }
    }
    printf("%d", nCr[n % 2][r]);
    return 0;
}

/*
5 2 100
*/
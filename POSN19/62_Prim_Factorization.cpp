#include <bits/stdc++.h>
using namespace std;

int prime_factors[40];

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        int sq = sqrt(n);
        for(int i = 2; i <= sq; i++) {
            while(n > 0 && n % i == 0) {
                cnt++;
                prime_factors[cnt] = i;
                n /= i;
            }
        }
        if(n > 1) { // left n is prime
            cnt++;
            prime_factors[cnt] = n;
            n = 1;
        }
        for(int i = 1; i <= cnt; i++) {
            printf("%d", prime_factors[i]);
            if(i != cnt)
                printf(" x ");
        }
        printf("\n");
    }
    return 0;
}
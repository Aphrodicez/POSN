#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e7;

int mark[MaxN + 100];
int prime[500000 + 100];

void gen_prime() {
    // Mark All Prime = 1
    for(int i = 1; i <= MaxN; i++)
        mark[i] = 1;
    mark[0] = mark[1] = 0;
    int sq = sqrt(MaxN);
    for(int i = 2; i <= sq; i++) {
        if(!mark[i])
            continue;
        // If i is Prime
        for(int j = i * i; j <= MaxN; j += i) {
            mark[j] = 0;
        }
    }
    int sz = 0;
    for(int i = 2; i <= MaxN && sz <= 500000; i++) {
        if(mark[i])
            prime[++sz] = i;
    }
}

int main() {
    gen_prime();
    int n;
    scanf("%d", &n);
    printf("%d\n", prime[n]);
    return 0;
}

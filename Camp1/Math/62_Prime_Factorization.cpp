/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Math [ Sqrt ]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> factors;

void factorize(int n) {
    factors.clear();
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1)
        factors.push_back(n);
    for(int i = 0; i < (int)factors.size() - 1; i++) {
        printf("%d x ", factors[i]);
    }
    printf("%d\n", factors[factors.size() - 1]);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int n;
        scanf("%d", &n);
        factorize(n);
    }
    return 0;
}

/*
3
100
17
18
*/
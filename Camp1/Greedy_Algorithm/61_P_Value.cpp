/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Greedy Algorithm
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> vec;

int main() {
    int n;
    scanf("%d", &n);
    if(n < 0) {
        printf("-1\n");
        return 0;
    }
    if(!n) {
        printf("10\n");
        return 0;
    }
    if(n <= 9) {
        printf("%d\n", n);
        return 0;
    }
    for(int i = 9; i >= 2; i--) {
        while(n % i == 0) {
            vec.push_back(i);
            n /= i;
        }
    }
    if(n > 1) {
        printf("-1");
        return 0;
    }
    sort(vec.begin(), vec.end());
    for(auto x : vec) {
        printf("%d", x);
    }
    printf("\n");
    return 0;
}

/*
10

12

13
*/
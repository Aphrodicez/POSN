#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int sq = sqrt(n);
    for(int i = 2; i <= sq; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    if(isPrime(n))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

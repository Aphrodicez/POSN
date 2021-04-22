/*
GCD Of n numbers
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a == 0 || b == 0)
        return a + b;
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main(){
    int n, GCD, num;
    scanf("%d %d", &n, &GCD);
    for(int i = 1; i < n; i++){
        scanf("%d", &num);
        GCD = gcd(GCD, num);
    }
    printf("%d", GCD);
    return 0;
}
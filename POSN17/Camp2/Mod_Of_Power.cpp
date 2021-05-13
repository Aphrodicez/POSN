/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Divide And Conquer
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int modOfPower(int a, int b, int c){
    if(b == 1)
        return (a % c);
    int half = modOfPower(a, b / 2, c);
    half %= c;
    half *= half;
    half %= c;
    if(b % 2){
        half *= a;
        half %= c;
    }
    return half;
}

void solve() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", modOfPower(a, b, c));
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--){
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
2 3 5
2 4 5
*/
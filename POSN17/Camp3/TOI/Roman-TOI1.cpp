/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 4e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int ans[5];

void roman(int n) {
    ans[4] += n / 100;
    n %= 100;
    ans[2] += n / 90;
    ans[4] += n / 90;
    n %= 90;
    ans[3] += n / 50;
    n %= 50;
    ans[2] += n / 40;
    ans[3] += n / 40;
    n %= 40;
    ans[2] += n / 10;
    n %= 10;
    ans[0] += n / 9;
    ans[2] += n / 9;
    n %= 9;
    ans[1] += n / 5;
    n %= 5;
    ans[0] += n / 4;
    ans[1] += n / 4;
    n %= 4;
    ans[0] += n / 1;
    n %= 1;
}

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        roman(i);
    }
    for(int i = 0; i < 5; i++) {
        printf("%d ", ans[i]);
    }
}

int main() {
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
5
*/
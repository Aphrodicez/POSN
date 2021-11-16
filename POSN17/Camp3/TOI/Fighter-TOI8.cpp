/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

void solve() {
    int n;
    scanf("%d", &n);
    int streak[] = {0, 0};
    int health[] = {n, n};
    for(int i = 1; i <= 2 * n; i++) {
        int val;
        scanf("%d", &val);
        ++streak[val & 1];
        streak[(val & 1) ^ 1] = 0;
        health[(val & 1) ^ 1] -= 1;
        if(streak[val & 1] >= 3)
            health[(val & 1) ^ 1] -= 2;
        if(health[(val & 1) ^ 1] <= 0) {
            printf("%d\n", val & 1);
            printf("%d\n", val);
            return ;
        }
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
6
7 5 2 4 8 1 3 9 11 12 13 14

8
1 2 3 4 5 6 7 8 9 10 2 4 6 8 10 12

10
1 2 3 4 5 6 7 8 9 10 11 13 15 16 17 18 19 20 21 22

12 
1 2 3 4 5 6 7 8 9 10 11 13 15 16 18 20 22 24 26 28 19 21 23 30 

9
1 2 3 4 5 6 7 8 9 11 13 10 12 14 15 17 19 16

9 
1 2 3 4 5 7 9 6 8 10 11 12 14 16 13 15 17 18
*/
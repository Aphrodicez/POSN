/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math [ Factorization ] + Brute Force
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

const int MaxN = 5e6 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

char pattern[2 * MaxN], tmp[MaxN];

void solve() {
    int n;
    scanf("%d", &n);
    scanf(" %s", (pattern + 1));
    strcpy(tmp + 1, pattern + 1);
    strcat(pattern + 1, tmp + 1);
    for(int sz = 1; sz <= sqrt(n); sz++) {
        if(n % sz)
            continue;
        if(!(strncmp(pattern + 1, pattern + sz + 1, n))) {
            printf("%d\n", sz);
            return ;
        } 
    }
    for(int sz = sqrt(n); sz >= 1; sz--) {
        if(n % sz)
            continue;
        if(!(strncmp(pattern + 1, pattern + (n / sz) + 1, n))) {
            printf("%d\n", n / sz);
            return ;
        }
    }
    printf("%d\n", n);
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
10
1010101010

10
1000000010

5
00000

5
10000
*/
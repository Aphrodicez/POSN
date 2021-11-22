/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Range Minimum Query [ Sparse Table ]
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

int rmq[20][MaxN];

void solve() {
    int n, q;
    scanf("%d %d", &n, &q);
    for(int j = 0; j <= n - 1; j++) {
        scanf("%d", &rmq[0][j]);
    }
    for(int i = 1; (1 << i) <= n - 1; i++) {
        for(int j = 0; j + (1 << i) - 1 <= n - 1; j++) {
            rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
        }
    }
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int sz = log2(r - l + 1);
        printf("%d\n", max(rmq[sz][l], rmq[sz][r - (1 << sz) + 1]));
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
6 3
2 -1 -7 8 6 9
0 4
1 2
3 5
*/
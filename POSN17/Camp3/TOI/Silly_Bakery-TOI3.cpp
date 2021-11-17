/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Greedy Algorithm + Math
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

int a[5];

void solve() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 5; j++) {
            int val;
            scanf("%d", &val);
            a[j] += val;   
        }
    }
    ans += a[0];
    a[0] = 0;
    a[3] += (a[4] + 1) / 2;
    a[4] = 0;

    int mn;
    mn = min(a[1], a[3]);
    ans += mn, a[1] -= mn, a[3] -= mn;
    ans += a[1];
    a[1] = 0;
    a[2] += (a[3] + 1) / 2;
    ans += (a[2] + 1) / 2;
    a[2] = 0;

    printf("%d\n", ans);
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
3
1 0 1 0 1
0 1 0 1 0
0 1 0 0 0

4
0 0 1 0 0
0 0 0 0 1
0 0 1 0 0
0 1 0 0 0

5
1 5 3 0 2
5 4 2 2 2
0 3 0 0 1
2 5 3 5 5
4 3 0 1 3

10
7028 9757 5254 2562 7322
7305 6976 7536 461 33
8780 6502 6399 8320 4806
910 5433 6944 4994 9049
4018 7940 3183 1276 3132
677 3867 3787 8511 2441
5598 6618 3276 1930 9180
598 9235 6155 8134 774
7267 6913 8356 3665 6312
3161 5654 1744 1183 648
*/
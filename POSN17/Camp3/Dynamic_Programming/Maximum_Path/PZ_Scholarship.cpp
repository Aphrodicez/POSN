/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Minimum Path]
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

i64 a[N][N], b[N][N], dpup[N][N], dpdown[N][N];

void solve() {
    i64 r, c, k;
    scanf("%lld %lld %lld", &r, &c, &k);
    for(int i = 1; i <= r; i++) {
        dpup[i][c + 1] = dpdown[i][0] = 1e18;
    }
    for(int j = 1; j <= c; j++) {
        dpup[r + 1][j] = dpdown[0][j] = 1e18;
    }
    for(i64 i = 1; i <= r; i++) {
        for(i64 j = 1; j <= c; j++) {
            scanf("%lld", &a[i][j]);
            dpdown[i][j] = a[i][j];
            if(i == 1 && j == 1)
                continue;
            dpdown[i][j] += min(dpdown[i - 1][j], dpdown[i][j - 1]);
        }
    }
    if(k == 1) {
        printf("%lld\n", dpdown[r][c]);
        return ;
    }
    for(i64 i = 1; i <= r; i++) {
        for(i64 j = 1; j <= c; j++) {
            scanf("%lld", &b[i][j]);
            dpup[i][j] = b[i][j];
        }
    }
    i64 ans = dpdown[r][c];
    for(i64 i = r; i >= 1; i--) {
        for(i64 j = c; j >= 1; j--) {
            if(i == r && j == c)
                continue;
            dpup[i][j] += min(dpup[i][j + 1], dpup[i + 1][j]);
            ans = min(ans, dpdown[i][j] + dpup[i][j] - max(a[i][j], b[i][j]));
        }
    }
    printf("%lld\n", ans);
}

int main() {
    i64 q;
    scanf("%lld", &q);
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
1
3 3 2
7 5 2
5 2 7
10 10 10
4 7 4
10 6 5
4 3 9
*/
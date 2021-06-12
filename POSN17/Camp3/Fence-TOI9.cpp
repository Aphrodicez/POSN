/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Quicksum 2D]
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

const int N = 5e2 + 10;
const int M = 2e5 + 10;

int qs[N][N];

void solve() {
    memset(qs, 0, sizeof qs);
    int r, c, m, i, j;
    scanf("%d %d", &r, &c);
    scanf("%d", &m);
    for(int k = 1; k <= m; k++) {
        scanf("%d %d", &i, &j);
        i++, j++;
        qs[i][j] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            int nowblock = qs[i][j];
            qs[i][j] += qs[i][j - 1] + qs[i - 1][j] - qs[i - 1][j - 1];
            if(nowblock)
                continue;
            ans = max(ans, 1);
            for(int k = 2; i - k >= 0 && j - k >= 0; k++) {
                int big = qs[i][j] - qs[i][j - k] - qs[i - k][j] + qs[i - k][j - k];
                int small = qs[i - 1][j - 1] - qs[i - 1][j - k + 1] - qs[i - k + 1][j - 1] + qs[i - k + 1][j - k + 1];
                if(big - small == 0)
                    ans = max(ans, k);
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int q = 2;
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
5 8
6
0 7 
1 3
2 0
3 6
4 2
4 5
5 5
8
0 0
0 4
4 0
4 4
0 1
2 0
2 4
4 3
*/
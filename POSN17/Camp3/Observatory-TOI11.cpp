/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Quicksum 2D] + [Laddersum]
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

const int N = 2e3 + 10;
const int M = 2e5 + 10;

int qsl[N][N], qsr[N][N], tri[N][N];

void solve() {
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    int ans = -2e9;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &qsl[i][j]);
            qsr[i][j] = qsl[i][j];
            qsl[i][j] += qsl[i - 1][j] + qsl[i][j - 1] - qsl[i - 1][j - 1];
            tri[i][j] = tri[i - 1][j - 1] + qsl[i][j] - qsl[i - 1][j];
            if(i - k < 0 || j - k < 0)
                continue;
            ans = max(ans, tri[i][j] - tri[i - k][j - k] - qsl[i][j - k] + qsl[i - k][j - k]);
        }
    }
    memset(tri, 0, sizeof tri);
    for(int i = 1; i <= r; i++) {
        for(int j = c; j >= 1; j--) {
            qsr[i][j] += qsr[i - 1][j] + qsr[i][j + 1] - qsr[i - 1][j + 1];
            tri[i][j] = tri[i - 1][j + 1] + qsr[i][j] - qsr[i - 1][j];
            if(i - k < 0 || j + k > c + 1)
                continue;
            ans = max(ans, tri[i][j] - tri[i - k][j + k] - qsr[i][j + k] + qsr[i - k][j + k]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
4 5 3 
1 2 -1 -4 -20 
-8 -3 4 2 1 
3 8 10 1 3 
-4 -1 1 7 -6

6 7 4 
-99 -99 -99 -99 -99 -99 -99
-99 -5 -99 -99 -99 -99 -99
-99 -5 -5 -99 -99 -99 -4 
-99 -5 -5 -5 -99 -5 -6 
-99 -5 -5 -5 -2 -5 -6 
-99 -99 -99 -5 -5 -5 -4
*/
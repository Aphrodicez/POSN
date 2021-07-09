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

const int N = 1e3 + 10;
const int M = 2e5 + 10;

int qs[N][N];

void solve() {
    int r, c, k, ans = 0 ;
    scanf("%d %d", &r, &c);
    scanf("%d", &k);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &qs[i][j]);
            qs[i][j] += qs[i][j - 1] + qs[i - 1][j] - qs[i - 1][j - 1];
            if(i - k < 0 || j - k < 0)
                continue;
            ans = max(ans, qs[i][j] - qs[i][j - k] - qs[i - k][j] + qs[i - k][j - k]);
        }
    }
    printf("%d", ans);
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
5 10 
2 
5 9 2 9 1 2 8 9 1 6 
9 1 3 9 8 4 2 1 5 7 
2 7 9 3 8 5 2 7 6 8 
1 6 2 1 7 7 1 9 4 1 
8 5 2 3 9 8 5 6 3 3

6 4 
3 
7 8 5 1 
0 3 5 2 
3 3 2 9 
9 7 8 9 
4 3 5 9 
8 6 5 2 
*/
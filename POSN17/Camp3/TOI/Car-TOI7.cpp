/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [ Minimum Path ]
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

const int MaxR = 1e2 + 10;
const int MaxC = 5e1 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

const int dir[] = {0, -1, 1, 0};
int dp[MaxR][MaxC];

void solve() {
    int c, stj, r;
    scanf("%d %d %d", &c, &stj, &r);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &dp[i][j]);
        }
    }
    for(int i = r - 1; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            if(dp[i][j])
                continue;
            dp[i][j] = 1;
            for(int k = 1; k <= 3; k++) {
                int jj = j + dir[k];
                if(jj < 1 || jj > c)
                    continue;
                dp[i][j] = min(dp[i][j], dp[i + 1][jj]);
            }
        }
    }
    int j = stj;
    for(int i = 0; i <= r - 1; i++) {
        for(int k = 1; k <= 3; k++) {
            int jj = j + dir[k];
            if(jj < 1 || jj > c)
                continue;
            if(!dp[i + 1][jj]) {
                j = jj;
                printf("%d\n", k);
                break;
            }
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
7 
5 
5 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 1 1 0 0 0 0 
1 0 1 1 1 1 1

5 
2 
3 
0 0 0 1 0 
0 1 1 0 0 
1 1 1 0 1
*/
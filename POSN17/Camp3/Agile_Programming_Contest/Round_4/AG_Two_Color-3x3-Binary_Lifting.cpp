/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Binary Lifting
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
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int N = 1e6 + 10;
const int M = 2e5 + 10;
const int MOD = 98765431;

int r1 = 3, r2 = 3, c2 = 3;

struct MATRIX {

};

void TESTCASE() {
    
}

i64 dp[63][3][3];

i64 baseCase[3][3] =  {{1, 1, 1}, {1, 0, 1}, {1, 1, 0}};
/*
[1, 1, 1]
[1, 0, 1]
[1, 1, 0]
*/

i64 dp0[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
/*
[1, 0, 0]
[0, 0, 0]
[0, 0, 0]
*/

i64 ans[3][3];

void solve() {
    int q;
    cin >> q;
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < r2; j++) {
            dp[0][i][j] = baseCase[i][j];
        }
    }
    for(int k = 1; k <= 60; k++) {
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++) {
                for(int x = 0; x < r1; x++) {
                    dp[k][i][j] += dp[k - 1][i][x] * dp[k - 1][x][j];
                    dp[k][i][j] %= MOD;
                }
            }
        }
    }
    while(q--) {
        i64 n;
        cin >> n;
        int k = 0;
        memcpy(ans, dp0, sizeof dp0);
        while(n) {
            if(n % 2) {
                i64 tmp[3][3];
                for(int i = 0; i < r1; i++) {
                    for (int j = 0; j < c2; j++) {
                        tmp[i][j] = 0;
                        for(int x = 0; x < r1; x++) {
                            tmp[i][j] += dp[k][i][x] * ans[x][j];
                            tmp[i][j] %= MOD;
                        }
                    }
                }
                memcpy(ans, tmp, sizeof tmp);
            }
            n /= 2;
            k++;
        }
        i64 sum = 0;
        for(int i = 0; i < 3; i++) {
            sum += ans[i][0];
            sum %= MOD;
        }
        cout << sum << "\n";
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
3
1
2
3
*/
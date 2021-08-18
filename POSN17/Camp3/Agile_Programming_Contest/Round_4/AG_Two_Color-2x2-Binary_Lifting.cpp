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

int r1 = 2, r2 = 2, c2 = 2;

struct MATRIX {

};

void TESTCASE() {
    
}

i64 dp[63][2][2];

i64 baseCase[2][2] =  {{1, 1}, {2, 1}};
/*
[1, 1]
[2, 1]
*/

i64 dp0[2][2] = {{1, 0}, {0, 0}};
/*
[1]
[0]
*/

i64 ans[2][2];

void solve() {
    int q;
    cin >> q;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            dp[0][i][j] = baseCase[i][j];
        }
    }
    for(int k = 1; k <= 60; k++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                for(int x = 0; x < 2; x++) {
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
                i64 tmp[2][2];
                for(int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        tmp[i][j] = 0;
                        for(int x = 0; x < 2; x++) {
                            tmp[i][j] += dp[k][i][x] * ans[x][j];
                            tmp[i][j] %= MOD;
                        }
                    }
                }
                memcpy(ans, tmp, sizeof tmp);
            }
            n >>= 1;
            k++;
        }
        i64 sum = 0;
        for(int i = 0; i < 2; i++) {
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
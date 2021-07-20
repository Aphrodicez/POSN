/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Levenshtein Edit Distance
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

struct GRAPH {
    
};

const int N = 1e3 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

char a[N], b[N];

int dp[2][N];

void solve() {
    memset(dp, 0, sizeof dp);
    cin >> (a + 1);
    cin >> (b + 1);
    int lena = strlen(a + 1), lenb = strlen(b + 1);
    for(int j = 1; j <= lenb; j++)
        dp[0][j] = j;
    for(int i = 1; i <= lena; i++) {
        dp[i % 2][0] = i;
        for(int j = 1; j <= lenb; j++) {
            if(a[i] == b[j]) {
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
                continue;
            }
            dp[i % 2][j] = min({dp[(i + 1) % 2][j], dp[i % 2][j - 1], dp[(i + 1) % 2][j - 1]}) + 1;
        }
    }
    cout << dp[lena % 2][lenb] << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
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
3
good
goodbye
peat
pot
kitten
sitting
*/
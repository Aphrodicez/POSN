/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Bitmasking
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

const int MaxN = 5e4 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long a[5][MaxN], dp[13][2];

vector <int> stateLists;

void solve() {
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for(int i = 0; i < 5; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= n; j++) {
        for(int k = 0; k < (int)stateLists.size(); k++) {
            int state = stateLists[k];
            dp[k][j % 2] = 0;
            for(int i = 0; i < 5; i++) {
                if(state & (1 << i)) {
                    dp[k][j % 2] += a[i][j];
                }
            }
            long long mx = 0;
            for(int lastk = 0; lastk < (int)stateLists.size(); lastk++) {
                int lastState = stateLists[lastk];
                if(lastState & state)
                    continue;
                mx = max(mx, dp[lastk][(j + 1) % 2]);
            }
            dp[k][j % 2] += mx;
        }
    }
    long long mx = 0;
    for(int state = 0; state < (int)stateLists.size(); state++) {
        mx = max(mx, dp[state][n % 2]);
    }
    cout << mx << "\n";
}

int main() {
    setIO();
    for(int i = 0; i <= (1 << 5) - 1; i++) {
        int j = 3;
        bool isValid = true;
        while(j <= i) {
            if((j & i) == j) {
                isValid = false;
                break;
            }
            j <<= 1;
        }
        if(!isValid)
            continue;
        stateLists.emplace_back(i);
    }
    int q = 1;
    cin >> q;
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
2
6
1 0 0 0 0 0
0 1 1 10 1 0
1 10 0 0 5 10
0 1 1 10 0 0
1 0 0 0 1 10
5
1 0 0 0 1
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
1 0 0 0 1
*/
/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Maximum Path - Minimum Path]
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

const int N = 2e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int a[N][N], dpmx[N][N], dpmn[N][N];

void solve() {
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= r; i++)
        dpmn[i][0] = dpmn[i][c + 1] = 1e9;
    for(int j = 1; j <= c; j++)
        dpmn[0][j] = dpmn[r + 1][j] = 1e9;
    dpmx[r][1] = dpmn[r][1] = a[r][1];
    for(int i = r; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            if(i == r && j == 1)
                continue;
            dpmx[i][j] = max(dpmx[i + 1][j], dpmx[i][j - 1]) + a[i][j];
            dpmn[i][j] = min(dpmn[i + 1][j], dpmn[i][j - 1]) + a[i][j];
        }
    }
    cout << dpmx[1][c] - dpmn[1][c] << "\n";
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
4 4
3 3 3 3
2 2 1 3
0 1 1 3
0 0 0 0
*/
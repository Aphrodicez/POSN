/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Minimum Path + Quicksum 1D]
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

const int N = 7e2 + 10;
const int M = 2e5 + 10;

void TESTCASE() {

}

int ul[N][N], ur[N][N], dl[N][N], dr[N][N];

int val[N][N], qsrow[N][N], qscol[N][N];

void solve() {
    int r, c;
    cin >> r >> c;
    for(int i = 0; i <= r + 1; i++) {
        for(int j = 0; j <= c + 1; j++) {
            ul[i][j] = ur[i][j] = dl[i][j] = dr[i][j] = 1e9;
        }
    }

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> val[i][j];
            qsrow[i][j] = qsrow[i][j - 1] + val[i][j];
            qscol[i][j] = qscol[i - 1][j] + val[i][j];
            ul[i][j] = val[i][j];
            if(i == 1 && j == 1)
                continue;
            ul[i][j] = min(ul[i - 1][j], ul[i][j - 1]) + val[i][j];
        }
    }
    for(int i = 1; i <= r; i++) {
        for(int j = c; j >= 1; j--) {
            ur[i][j] = val[i][j];
            if(i == 1 && j == c)
                continue;
            ur[i][j] = min(ur[i - 1][j], ur[i][j + 1]) + val[i][j];
        }
    }
    for(int i = r; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            dl[i][j] = val[i][j];
            if(i == r && j == 1)
                continue;
            dl[i][j] = min(dl[i + 1][j], dl[i][j - 1]) + val[i][j];
        }
    }
    for(int i = r; i >= 1; i--) {
        for(int j = c; j >= 1; j--) {
            dr[i][j] = val[i][j];
            if(i == r && j == c)
                continue;
            dr[i][j] = min(dr[i + 1][j], dr[i][j + 1]) + val[i][j];
        }
    }
    int ans = 1e9;
    int bestRow = 1e9, bestCol = 1e9;
    for(int i = 1; i <= r; i++) {
        bestRow = 1e9;
        for(int j = 1; j <= c; j++) {
            bestRow = min(bestRow, ul[i][j] + dl[i][j] - 2 * val[i][j] - qsrow[i][j - 1]);
            ans = min(ans, bestRow + ur[i][j] + dr[i][j] - 2 * val[i][j] + qsrow[i][j]);
        }
    }
    for(int j = 1; j <= c; j++) {
        bestCol = 1e9;
        for(int i = 1; i <= r; i++) {
            bestCol = min(bestCol, ul[i][j] + ur[i][j] - 2 * val[i][j] - qscol[i - 1][j]);
            ans = min(ans, bestCol + dl[i][j] + dr[i][j] - 2 * val[i][j] + qscol[i][j]);
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
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
2
3 3
1 1 1
1 1 1
1 1 1
5 10
2 6 1 7 4 8 5 6 9 6
8 8 7 6 8 3 6 1 3 3
1 4 3 1 7 5 8 5 1 4
9 5 6 8 5 7 8 5 4 9
8 6 7 8 9 9 2 6 5 1
*/

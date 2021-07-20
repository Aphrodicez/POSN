/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming
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

int a[N][N];

int MaxLeftRight[N][N];

void solve() {
    memset(MaxLeftRight, 0, sizeof (MaxLeftRight));
    int r, c;
    cin >> r >> c;
    char x;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> x;
            a[i][j] = x - '0';
            if(!a[i][j])
                continue;
            MaxLeftRight[i][j] = MaxLeftRight[i][j - 1] + 1;
        }
    }
    for(int i = 1; i <= r; i++) {
        int len = 0;
        for(int j = c; j >= 1; j--) {
            if(!a[i][j]) {
                len = 0;
                continue;
            }
            len++;
            MaxLeftRight[i][j] = max(MaxLeftRight[i][j], len);
        }
    }
    int ans = 0;
    for(int j = 1; j <= c; j++) {
        int len = 0;
        for(int i = 1; i <= r; i++) {
            if(!a[i][j]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, MaxLeftRight[i][j] + len - 1);
        }
    }
    for(int j = 1; j <= c; j++) {
        int len = 0;
        for(int i = r; i >= 1; i--) {
            if(!a[i][j]) {
                len = 0;
                continue;
            }
            len++;
            ans = max(ans, MaxLeftRight[i][j] + len - 1);
        }
    }
    cout << ans << "\n";
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
2
4 5
11110
11011
01111
11110
2 5
01110
11000
*/
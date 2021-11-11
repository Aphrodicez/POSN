/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Brute Force Algorithm
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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

void solve() {
    int n, h;
    cin >> n >> h;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if(val <= h) {
            ans = max(ans, val);
        }
    }
    cout << ans << "\n";
}

int main() {
    setIO();
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
4 40
10
50
40
20

2 99
100
99
*/
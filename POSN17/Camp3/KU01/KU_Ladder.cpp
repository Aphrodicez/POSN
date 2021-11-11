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

const int MaxN = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

int a[MaxN];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int now = 0;
    for(int i = 1; i <= m; i++) {
        int val;
        cin >> val;
        now += val;
        now = max(now, 0);
        now = min(now, n);
        now += a[now];
        now = max(now, 0);
        now = min(now, n);
        if(now == n) {
            cout << now << "\n";
            return ;
        }
    }
    cout << now << "\n";
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
5 3
0 0 0 0 0
3 3 2

5 2
2 0 0 0 0
1 1

5 2
0 0 0 -10 0
2 2
*/
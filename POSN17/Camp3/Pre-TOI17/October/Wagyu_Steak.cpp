/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Two Pointers
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long qs[MaxN];

int dp[MaxN];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i];
        qs[i] += qs[i - 1];
    }
    int j = 1;
    for(int i = 1; i <= n; i++) {
        while(j <= i && qs[i] - qs[j - 1] > m) {
            j++;
            continue;
        }
        while(j <= i && qs[i] - qs[j] >= m) {
            j++;
            continue;
        }
        if(qs[i] - qs[j - 1] == m)
            dp[i] = j;
        else
            dp[i] = dp[i - 1];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(dp[r] >= l)
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }
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
7 10 5
9 3 4 2 1 3 7
1 4
2 6
3 7
5 6
3 6
*/  
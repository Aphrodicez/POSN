/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Ad - Hoc]
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

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dpl[2][N], dpr[2][N];

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    a += a;
    for(int i = 2 * n; i >= 1; i--) {
        if(a[i - 1] == 'w') {
            dpr[0][i] =  dpr[0][i + 1] + 1;
            dpr[1][i] =  dpr[1][i + 1] + 1;
            continue;
        }
        if(a[i - 1] == 'r') {
            dpr[0][i] = dpr[0][i + 1] + 1;
            dpr[1][i] = 0;
            continue;
        }
        if(a[i - 1] == 'b') {
            dpr[1][i] = dpr[1][i + 1] + 1;
            dpr[0][i] = 0;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] == 'w') {
            dpl[0][i] = dpl[0][i - 1] + 1;
            dpl[1][i] = dpl[1][i - 1] + 1;
            ans = max(ans, dpl[0][i] + dpr[1][i + 1]);
            ans = max(ans, dpl[1][i] + dpr[0][i + 1]);
        }
        if(a[i - 1] == 'r') {
            dpl[0][i] = dpl[0][i - 1] + 1;
            dpl[1][i] = 0;
            ans = max(ans, dpl[0][i] + dpr[1][i + 1]);
        }
        if(a[i - 1] == 'b') {
            dpl[1][i] = dpl[1][i - 1] + 1;
            dpl[0][i] = 0;
            ans = max(ans, dpl[1][i] + dpr[0][i + 1]);
        }
    }
    ans = min(ans, n);
    cout << ans << "\n";
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
29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
*/
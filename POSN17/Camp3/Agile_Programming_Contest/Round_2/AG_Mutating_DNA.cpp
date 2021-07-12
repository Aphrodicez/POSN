/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Dynamic Programming [Quicksum] + Math
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

const int N = 1e6 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

int dp[3][3][N];

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a;
    cin >> b;
    unordered_map <char, int> mapp;
    mapp['A'] = 0;
    mapp['T'] = 1;
    mapp['C'] = 2;

    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                dp[k][l][i] += dp[k][l][i - 1];
            }
        }
        dp[mapp[a[i - 1]]][mapp[b[i - 1]]][i]++;
    }
    int l, r;
    while(q--) {
        int ans = 0, cnt;
        cin >> l >> r;
        l++, r++;

        int AtoT = dp[mapp['A']][mapp['T']][r] - dp[mapp['A']][mapp['T']][l - 1];
        int AtoC = dp[mapp['A']][mapp['C']][r] - dp[mapp['A']][mapp['C']][l - 1];
        int TtoA = dp[mapp['T']][mapp['A']][r] - dp[mapp['T']][mapp['A']][l - 1];
        int TtoC = dp[mapp['T']][mapp['C']][r] - dp[mapp['T']][mapp['C']][l - 1];
        int CtoA = dp[mapp['C']][mapp['A']][r] - dp[mapp['C']][mapp['A']][l - 1];
        int CtoT = dp[mapp['C']][mapp['T']][r] - dp[mapp['C']][mapp['T']][l - 1];
        
        int A = AtoC + AtoT;
        int T = TtoA + TtoC;
        int C = CtoA + CtoT;
        int Abelow = CtoA + TtoA;
        int Tbelow = AtoT + CtoT;
        int Cbelow = AtoC + TtoC;

        if(A != Abelow || T != Tbelow || C != Cbelow) {
            cout << -1 << "\n";
            continue;
        }
        
        cnt = min(AtoT, TtoA);
        ans += cnt;
        A -= cnt;
        T -= cnt;

        cnt = min(AtoC, CtoA);
        ans += cnt;
        A -= cnt;
        C -= cnt;

        cnt = min(TtoC, CtoT);
        ans += cnt;
        T -= cnt;
        C -= cnt;

        if(A != T || A != C) {
            cout << -1 << "\n";
            continue;
        }
        cout << ans + 2 * A << "\n";
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
6 3
ATACAT
ACTATA
1 3
4 5
3 5
*/
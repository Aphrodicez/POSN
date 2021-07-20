/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Longest Palindromic Substring
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

char s[N];

bool palin[N][N];

void solve() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int mx = 1;
    int idx = 1;
    for(int i = 1; i <= n; i++)
        palin[i][i] = true;
    for(int i = 1; i <= n - 1; i++) {
        palin[i][i + 1] = s[i] == s[i + 1];
        if(palin[i][i + 1] && 2 > mx) {
            mx = 2;
            idx = i;
        }
    }
    for(int sz = 3; sz <= n; sz++) {
        for(int l = 1; l + sz - 1 <= n; l++) {
            int r = l + sz - 1;
            palin[l][r] = palin[l + 1][r - 1] & (s[l] == s[r]);
            if(palin[l][r] && sz > mx) {
                mx = sz;
                idx = l;
            }
        }
    }
    for(int i = idx; i <= idx + mx - 1; i++)
        cout << s[i];
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
banana

abracadabra
*/
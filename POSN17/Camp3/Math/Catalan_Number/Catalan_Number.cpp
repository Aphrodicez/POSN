/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math [Catalan Number]
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
const int MOD = 1e4 + 9;

void TESTCASE() {
    
}

int fact[2 * N];

int inverse(int b) {
    for(int i = 0; i < MOD; i++) {
        if(b * i % MOD == 1)
            return i;
    }
}

void solve() {
    fact[0] = 1;
    for(int i = 1; i <= 2 * (N - 10); i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    int n;
    cin >> n;
    int b = 1;
    b *= fact[n];
    b %= MOD;
    b *= fact[n];
    b %= MOD;
    b *= n + 1;
    b %= MOD;
    cout << (fact[2*n] % MOD * inverse(b)) % MOD;
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*

*/
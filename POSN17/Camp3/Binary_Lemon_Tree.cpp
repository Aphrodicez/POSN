/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Catalan Number
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

const int N = 1e4 + 10;
const int M = 2e5 + 10;

const int MOD = 909091;

i64 catalan[N];

void TESTCASE() {
    
}

void solve() {
    int n;
    cin >> n;
    catalan[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            catalan[i] += (catalan[j] % MOD) * (catalan[i - j - 1] % MOD);
            catalan[i] %= MOD;
        }
    }
    cout << catalan[n];
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

*/
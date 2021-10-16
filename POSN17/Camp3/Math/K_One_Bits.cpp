/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math [ Stars and Bars ]
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

const int MaxN = 1e7 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long nCr(long long n, long long r) {
    long long sum = 1;
    for(long long i = max(r, (n - r)) + 1; i <= n; i++) {
        sum *= i;
    }
    for(long long i = 1; i <= min(r, n - r); i++) {
        sum /= i;
    }
    return sum;
}

bool ans[MaxN];

void solve() {
    long long n, k;
    cin >> n >> k;
    long long cntZero, cntDigit;
    for(cntZero = 0; ; cntZero++) {
        long long res = nCr((k - 1) + cntZero, cntZero);
        if(n - res <= 0)
            break;
        n -= res;
    }
    cntDigit = cntZero + (k - 1);
    long long last = 0;
    for(int idx = 1; idx <= cntZero; idx++) {
        for(int i = last + 1; i <= cntDigit + 1; i++) {
            long long res = nCr(cntDigit - i, cntZero - idx);
            if(n <= res) {
                last = i;
                ans[last] = 1;
                break;
            }
            n -= res;
        }
    }
    for(int i = 0; i <= cntDigit; i++) {
        cout << 1 - ans[i];
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
7 3
*/
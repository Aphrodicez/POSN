/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Divide and Conquer + Math
    Status	: Accepted
    Created	: 19 August 2021 [11:19]
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

struct ALGEBRA {
    int a, b, c, d;
};

int MOD;

ALGEBRA operator* (const ALGEBRA &A, const ALGEBRA &B) {
    ALGEBRA tmp;
    tmp.a = (A.a * B.a) + (2 * A.b * B.b) + (3 * A.c * B.c) + (6 * A.d * B.d);
    tmp.a %= MOD;
    tmp.b = (A.a * B.b) + (A.b * B.a) + (3 * A.c * B.d) + (3 * A.d * B.c);
    tmp.b %= MOD;
    tmp.c = (A.a * B.c) + (A.c * B.a) + (2 * A.b * B.d) + (2 * A.d * B.b);
    tmp.c %= MOD;
    tmp.d = (A.a * B.d) + (A.d * B.a) + (A.b * B.c) + (A.c * B.b);
    tmp.d %= MOD;
    return tmp;
}

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

ALGEBRA Base;

ALGEBRA ModOfPower(int n) {
    if(n == 1)
        return Base;
    ALGEBRA prod = ModOfPower(n / 2);
    prod = prod * prod;
    if(n % 2)
        prod = prod * Base;
    return prod;
}

void solve() {
    int n;
    cin >> Base.a >> Base.b >> Base.c >> n >> MOD;
    Base.a %= MOD;
    Base.b %= MOD;
    Base.c %= MOD;
    Base.d %= MOD;
    ALGEBRA ans = ModOfPower(n);
    cout << ans.a << " " << ans.b << " " << ans.c << " " << ans.d << "\n";
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
1
1 1 1 2 10
*/
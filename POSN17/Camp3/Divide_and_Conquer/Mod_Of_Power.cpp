/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Mod Of Power
    Status	: Accepted
    Created	: 19 August 2021 [10:50]
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

int ModOfPower(int a, int b, int c) {
    if(b == 0)
        return 1 % c;
    if(b == 1)
        return a % c;
    int prod = ModOfPower(a, b / 2, c);
    prod *= prod;
    prod %= c;
    if(b % 2)
        prod *= a;
    return prod % c;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ModOfPower(a, b, c) << "\n";
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
2
2 3 5
2 4 5
*/
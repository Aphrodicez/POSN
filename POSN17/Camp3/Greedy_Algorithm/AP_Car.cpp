/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

struct A {
    i64 st, en;
    bool operator < (const A &o) const {
        if(st != o.st)
            return st < o.st;
        return en > o.en;
    }
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

A a[N];

void solve() {
    int n;
    i64 t;
    cin >> n >> t;
    i64 st, v;
    for(int i = 0; i < n; i++) {
        cin >> st >> v;
        a[i] = {st, st + v * t};
    }
    sort(a, a + n); 
    i64 lastst = -1, lasten = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(((lastst != a[i].st)&&(lasten < a[i].en)) || ((lastst == a[i].st) && (lasten <= a[i].en))) {
            cnt++;
            lastst = a[i].st;
            lasten = a[i].en;
        }
    }
    cout << cnt << "\n";
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
5 2
0 10
0 5
10 5
8 8
9 7
*/
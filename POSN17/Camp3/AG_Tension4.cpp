/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math + Binary Search
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

const int N = 1e9 + 10;
const int M = 2e5 + 10;

i64 sqrt(i64 n) {
    i64 l = 0, r = n;
    while(l < r) {
        i64 mid = l + (r - l + 1) / 2;
        if(mid <= n / mid)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

void solve() {
    i64 l, r;
    cin >> l >> r;
    cout << (sqrt(r) - sqrt(l - 1)) + (sqrt(r / 2) - sqrt((l - 1) / 2)) << "\n";
}

int main() {
    setIO();
    i64 n, q;
    cin >> n >> q;
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
7 3
1 2
4 7
3 5
*/
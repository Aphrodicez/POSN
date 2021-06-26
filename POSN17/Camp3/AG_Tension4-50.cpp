/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math
    Status	: Time Limit Exceeded [50]
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

set <long long> mset;

vector <long long> vec;

void solve() {
    i64 l, r;
    cin >> l >> r;
    cout << upper_bound(all(vec), r) - lower_bound(all(vec), l) << "\n";
}

int main() {
    setIO();
    i64 n, q;
    cin >> n >> q;
    for(i64 i = 1; i <= sqrt(n); i++) {
        mset.insert(i * i);
        mset.insert(2 * i * i);
    }
    for(auto x : mset) {
        vec.push_back(x);
    }
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
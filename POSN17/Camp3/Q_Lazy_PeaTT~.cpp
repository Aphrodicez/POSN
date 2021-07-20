/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Searching
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

unordered_map <int, vector <int>> mapp;

void TESTCASE() {
    
}

void solve() {
    int n, q;
    cin >> n >> q;
    int val;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        mapp[val].push_back(i);
    }
    while(q--) {
        int l, r, val;
        cin >> l >> r >> val;
        vector <int> vec = mapp[val];
        int ub = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        int lb = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        cout << ub - lb << "\n";
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
10 8
1 2 1 2 1 2 3 2 3 3
1 2 1
1 3 1
1 4 2
1 5 2
2 5 4
2 6 3
6 9 0
7 10 3
*/
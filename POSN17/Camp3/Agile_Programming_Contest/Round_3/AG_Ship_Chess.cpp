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

struct GRAPH {
    
};

const int N = 1e9 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

unordered_map <int, int> rowXor, colXor, freqRowXor, freqColXor;
map <pair <int, int>, int> ship;


i64 ans = 0;

int n;

void placeShip(int i, int j, int val) {
    ans -= n - freqColXor[rowXor[i]];
    ans -= n - freqRowXor[colXor[j]];
    if(rowXor[i] != colXor[j])
        ans++;
    freqRowXor[rowXor[i]]--;
    freqColXor[colXor[j]]--;
    /// Place Ship
    rowXor[i] ^= val;
    colXor[j] ^= val;
    freqRowXor[rowXor[i]]++;
    freqColXor[colXor[j]]++;
    ans += n - freqColXor[rowXor[i]];
    ans += n - freqRowXor[colXor[j]];
    if(rowXor[i] != colXor[j])
        ans--;
}

void solve() {
    int k, p;
    cin >> n >> k >> p;
    freqRowXor[0] = freqColXor[0] = n;
    int i, j, val;
    while(k--) {
        cin >> i >> j >> val;
        ship[make_pair(i, j)] = val;
        placeShip(i, j, val);
    }
    int i1, j1, i2, j2;
    while(p--) {
        cin >> i1 >> j1 >> i2 >> j2;
        val = ship[make_pair(i1, j1)];
        ship.erase(make_pair(i1, j1));
        placeShip(i1, j1, val);
        ship[make_pair(i2, j2)] = val;
        placeShip(i2, j2, val);
        cout << ans << "\n";
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
2 2 2
1 1 1
2 2 1
2 2 2 1
1 1 1 2

3 3 4
1 1 1
2 2 2
2 3 3
2 3 3 3
3 3 3 1
1 1 1 2
3 1 3 2
*/
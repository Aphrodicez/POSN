/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Math
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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long ceil_function(long long a, long long b) {
    return a ? ((a - 1) / b) + 1 : 0;
}

bool impossible(long long MIN, long long MAX, long long MEAN, long long MEDIAN) {
    if(MAX < MIN || MAX < MEAN || MAX < MEDIAN) {
        return true;
    }
    if(MIN > MEAN || MIN > MEDIAN)
        return true;
    return false;
}

long long base_case(long long MIN, long long MAX, long long MEAN, long long MEDIAN) {
    if(MIN == MAX && MIN == MEAN && MIN == MEDIAN)
        return 1;
    if((MEAN == MEDIAN) && (MIN + MAX == 2 * MEAN)) {
        return 2;
    }
    return 0;
}

long long odd(long long MIN, long long MAX, long long MEAN, long long MEDIAN) {
    long long need = (MIN + MAX + MEDIAN) - (3 * MEAN);
    long long add;
    if(need >= 0) {
        add = (2 * MEAN) - (MIN + MEDIAN);
    }
    else if(need < 0) {
        add = (MAX + MEDIAN) - (2 * MEAN);
        need = -need;
    }
    if(add <= 0)
        return 1e18;
    return ceil_function(need, add) * 2 + 3;
}

long long even(long long MIN, long long MAX, long long MEAN, long long MEDIAN) {
    long long need = (MIN + MAX + MEDIAN * 2) - (4 * MEAN);
    long long add;
    if(need >= 0) {
        add = (2 * MEAN) - (MIN + MEDIAN);
    }
    else if(need < 0) {
        add = (MAX + MEDIAN) - (2 * MEAN);
        need = -need;
    }
    if(add <= 0)
        return 1e18;
    return ceil_function(need, add) * 2 + 4;
}

void solve() {
    long long MIN, MAX, MEAN, MEDIAN;
    cin >> MIN >> MAX >> MEAN >> MEDIAN;
    if(impossible(MIN, MAX, MEAN, MEDIAN)) {
        cout << "IMPOSSIBLE" << "\n";
        return ;
    }
    if(base_case(MIN, MAX, MEAN, MEDIAN)) {
        cout << base_case(MIN, MAX, MEAN, MEDIAN) << "\n";
        return ;
    }
    long long ans = 1e18;
    ans = min(ans, odd(MIN, MAX, MEAN, MEDIAN));
    ans = min(ans, even(MIN, MAX, MEAN, MEDIAN));
    if(ans == 1e18)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << ans << "\n";
}

int main() {
    setIO();
    int q = 1;
    cin >> q;
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
5
6 4 5 1
7 7 8 8
2 2 2 2
3 7 5 5
1 4 3 4
*/  
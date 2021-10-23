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
const int MOD = 25621;

void TESTCASE() {
    
}

unordered_set <long long> set_x, set_y;

void solve() {
    set_x.clear();
    set_y.clear();
    long long n, m;
    int k;
    scanf("%lld %lld %d", &n, &m, &k);
    for(int i = 1; i <= k; i++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        set_x.insert(x);
        set_y.insert(y);
    }
    printf("%lld\n", ((n - (long long)set_x.size()) % MOD) * ((m - (long long)set_y.size()) % MOD) % MOD);
}

int main() {
    setIO();
    int q = 1;
    scanf("%d", &q);  
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
2
4 5 3
1 2
3 5
3 4
100000 100000 3
1 2
3 5
3 4
*/
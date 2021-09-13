/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sweep Line Algorithm
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

struct POINT {
    int idx;
    long long val;
    bool operator < (const POINT &o) const {
        if(idx != o.idx)
            return idx < o.idx;
        return val < o.val;
    }
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <POINT> eventPoint;

void solve() {
    eventPoint.clear();
    int n;
    long long x, y, z;
    cin >> n >> x >> y >> z;
    int l, r;
    for(int i = 1; i <= n; i++) {
        cin >> l >> r;
        eventPoint.push_back({l, y - x});
        eventPoint.push_back({r + 1, z - y});
    }
    sort(eventPoint.begin(), eventPoint.end());
    long long ans = 0, sum = x * n;
    for(auto x : eventPoint) {
        sum += x.val;
        ans = max(ans, sum);
    }
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
1
4 7 9 6
5 8
3 4
13 20
7 10
*/
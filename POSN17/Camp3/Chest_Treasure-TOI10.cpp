/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Sweep Line Algorithm + Math
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
    int idx, type;
    long long factor[4];
    bool operator < (const POINT &o) const {
        if(idx != o.idx)
            return idx < o.idx;
        return type < o.type;
    }
};

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

vector <POINT> eventPoint;

const int Prime_Factor[] = {2, 3, 5, 7};

void solve() {
    int m, n;
    cin >> m >> n;
    int l, r, val;
    for(int i = 1; i <= m; i++) {
        cin >> val >> l >> r;
        POINT now;
        for(int k = 0; k < 4; k++) {
            now.factor[k] = 0;
            while(val % Prime_Factor[k] == 0) {
                now.factor[k]++;
                val /= Prime_Factor[k];
            }
        }
        now.idx = l;
        now.type = 1;
        eventPoint.push_back(now);
        now.idx = r + 1;
        now.type = -1;
        eventPoint.push_back(now);
    }
    sort(eventPoint.begin(), eventPoint.end());
    long long prod = 1, ans = 0, sum = 0;
    POINT now = {0, 0, {0, 0, 0, 0}};
    for(int i = 0; i < (int)eventPoint.size() - 1; i++) {
        prod = 1;
        for(int k = 0; k < 4; k++) {
            now.factor[k] += eventPoint[i].type * eventPoint[i].factor[k];
            prod *= (now.factor[k] + 1);
        }
        if(prod > ans) {
            ans = prod;
            sum = 0;
        }
        if(prod == ans) {
            sum += eventPoint[i + 1].idx - eventPoint[i].idx;
        }
    }
    cout << ans << " " << sum << "\n";
}

int main() {
    setIO();
    int q = 1;
    
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
5 10
3 0 4
2 2 3
5 4 7
6 7 9
2 3 3
*/

/*
8 10
4 0 3
3 3 6
5 4 6
2 4 6
10 0 1
9 5 6
7 0 3
2 3 4
*/
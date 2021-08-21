/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Divide and Conquer [Closest Pair of Points]
    Status	: Accepted
    Created	: 20 August 2021 [22:23]
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

struct POINT {
    double x, y;
};

bool cmpx(const POINT &a, const POINT &b) {
    return a.x < b.x;
}

bool cmpy(const POINT &a, const POINT &b) {
    return a.y < b.y;
}

const int N = 1e5 + 10;
const int M = 2e5 + 10;

void TESTCASE() {
    
}

POINT a[N];

double euclideanDistance(const POINT &a, const POINT &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double brute(int l, int r) {
    double mn = 2e9;
    if(l >= r)
        return mn;
    for(int i = l; i <= r - 1; i++) {
        for(int j = i + 1; j <= r; j++) {
            mn = min(mn, euclideanDistance(a[i], a[j]));
        }
    }
    return mn;
}

double stripClosestPair(vector <POINT> strip, double mn) {
    for(int i = 0; i < strip.size() - 1; i++) {
        for(int j = i + 1; j < strip.size() && strip[j].y - strip[i].y < mn; j++) {
            mn = min(mn, euclideanDistance(strip[i], strip[j]));
        }
    }
    return mn;
}

double closestPairOfPoints(int l, int r) {
    if(r - l + 1 <= 3)
        return brute(l, r);    
    int mid = (l + r) / 2;
    double mn = min(closestPairOfPoints(l, mid), closestPairOfPoints(mid + 1, r));
    vector <POINT> strip;
    for(int i = l; i <= r; i++) {
        if(abs(a[i].x - a[mid].x) < mn)
            strip.push_back(a[i]);
    }
    sort(strip.begin(), strip.end(), cmpy);
    mn = min(mn, stripClosestPair(strip, mn));
     return mn;
}

void solve() {
    int n;
    double r, d;
    cin >> n >> r >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, cmpx);
    if(closestPairOfPoints(1, n) < (d + 2 * r))
        cout << "N" << "\n";
    else
        cout << "Y" << "\n";
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
5
2 1 1 0 0 4 0
2 1 1 0 0 2 0
3 1 2 0 0 -2 2 2 1
3 1 2 0 0 4 1 -4 0
3 1 2 0 0 3 1 -4 0
*/